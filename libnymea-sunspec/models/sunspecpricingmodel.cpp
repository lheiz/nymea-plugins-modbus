/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2021, nymea GmbH
* Contact: contact@nymea.io
*
* This fileDescriptor is part of nymea.
* This project including source code and documentation is protected by
* copyright law, and remains the property of nymea GmbH. All rights, including
* reproduction, publication, editing and translation, are reserved. The use of
* this project is subject to the terms of a license agreement to be concluded
* with nymea GmbH in accordance with the terms of use of nymea GmbH, available
* under https://nymea.io/license
*
* GNU Lesser General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the
* terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; version 3. This project is distributed in the hope that
* it will be useful, but WITHOUT ANY WARRANTY; without even the implied
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this project. If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under
* contact@nymea.io or see our FAQ/Licensing Information on
* https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "sunspecpricingmodel.h"
#include "sunspecconnection.h"

SunSpecPricingModel::SunSpecPricingModel(SunSpecConnection *connection, quint16 modbusStartRegister, quint16 length, QObject *parent) :
    SunSpecModel(connection, modbusStartRegister, 125, 8, parent)
{
    //Q_ASSERT_X(length == 8,  "SunSpecPricingModel", QString("model length %1 given in the constructor does not match the model length from the specs %2.").arg(length).arg(modelLength()).toLatin1());
    Q_UNUSED(length)
    initDataPoints();
}

SunSpecPricingModel::~SunSpecPricingModel()
{

}

QString SunSpecPricingModel::name() const
{
    return "pricing";
}

QString SunSpecPricingModel::description() const
{
    return "Pricing Signal  ";
}

QString SunSpecPricingModel::label() const
{
    return "Pricing";
}

SunSpecPricingModel::ModenaFlags SunSpecPricingModel::modEna() const
{
    return m_modEna;
}

QModbusReply *SunSpecPricingModel::setModEna(ModenaFlags modEna)
{
    Q_UNUSED(modEna)
    return nullptr;
}
SunSpecPricingModel::Sigtype SunSpecPricingModel::sigType() const
{
    return m_sigType;
}

QModbusReply *SunSpecPricingModel::setSigType(Sigtype sigType)
{
    Q_UNUSED(sigType)
    return nullptr;
}
float SunSpecPricingModel::sig() const
{
    return m_sig;
}

QModbusReply *SunSpecPricingModel::setSig(float sig)
{
    Q_UNUSED(sig)
    return nullptr;
}
quint16 SunSpecPricingModel::winTms() const
{
    return m_winTms;
}

QModbusReply *SunSpecPricingModel::setWinTms(quint16 winTms)
{
    Q_UNUSED(winTms)
    return nullptr;
}
quint16 SunSpecPricingModel::rvtTms() const
{
    return m_rvtTms;
}

QModbusReply *SunSpecPricingModel::setRvtTms(quint16 rvtTms)
{
    Q_UNUSED(rvtTms)
    return nullptr;
}
quint16 SunSpecPricingModel::rmpTms() const
{
    return m_rmpTms;
}

QModbusReply *SunSpecPricingModel::setRmpTms(quint16 rmpTms)
{
    Q_UNUSED(rmpTms)
    return nullptr;
}
quint16 SunSpecPricingModel::pad() const
{
    return m_pad;
}
void SunSpecPricingModel::processBlockData()
{
    // Scale factors
    m_sigSf = m_dataPoints.value("Sig_SF").toInt16();

    // Update properties according to the data point type
    m_modEna = static_cast<ModenaFlags>(m_dataPoints.value("ModEna").toUInt16());
    m_sigType = static_cast<Sigtype>(m_dataPoints.value("SigType").toUInt16());
    m_sig = m_dataPoints.value("Sig").toFloatWithSSF(m_sigSf);
    m_winTms = m_dataPoints.value("WinTms").toUInt16();
    m_rvtTms = m_dataPoints.value("RvtTms").toUInt16();
    m_rmpTms = m_dataPoints.value("RmpTms").toUInt16();
    m_pad = m_dataPoints.value("Pad").toUInt16();

    qCDebug(dcSunSpec()) << this;
}

void SunSpecPricingModel::initDataPoints()
{
    SunSpecDataPoint modelIdDataPoint;
    modelIdDataPoint.setName("ID");
    modelIdDataPoint.setLabel("Model ID");
    modelIdDataPoint.setDescription("Model identifier");
    modelIdDataPoint.setMandatory(true);
    modelIdDataPoint.setSize(1);
    modelIdDataPoint.setAddressOffset(0);
    modelIdDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(modelIdDataPoint.name(), modelIdDataPoint);

    SunSpecDataPoint modelLengthDataPoint;
    modelLengthDataPoint.setName("L");
    modelLengthDataPoint.setLabel("Model Length");
    modelLengthDataPoint.setDescription("Model length");
    modelLengthDataPoint.setMandatory(true);
    modelLengthDataPoint.setSize(1);
    modelLengthDataPoint.setAddressOffset(1);
    modelLengthDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(modelLengthDataPoint.name(), modelLengthDataPoint);

    SunSpecDataPoint modEnaDataPoint;
    modEnaDataPoint.setName("ModEna");
    modEnaDataPoint.setLabel("ModEna");
    modEnaDataPoint.setDescription("Is price-based charge/discharge mode active?");
    modEnaDataPoint.setMandatory(true);
    modEnaDataPoint.setSize(1);
    modEnaDataPoint.setAddressOffset(2);
    modEnaDataPoint.setBlockOffset(0);
    modEnaDataPoint.setSunSpecDataType("bitfield16");
    modEnaDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(modEnaDataPoint.name(), modEnaDataPoint);

    SunSpecDataPoint sigTypeDataPoint;
    sigTypeDataPoint.setName("SigType");
    sigTypeDataPoint.setLabel("SigType");
    sigTypeDataPoint.setDescription("Meaning of the pricing signal. When a Price schedule is used, type must match the schedule range variable description.");
    sigTypeDataPoint.setSize(1);
    sigTypeDataPoint.setAddressOffset(3);
    sigTypeDataPoint.setBlockOffset(1);
    sigTypeDataPoint.setSunSpecDataType("enum16");
    sigTypeDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(sigTypeDataPoint.name(), sigTypeDataPoint);

    SunSpecDataPoint sigDataPoint;
    sigDataPoint.setName("Sig");
    sigDataPoint.setLabel("Sig");
    sigDataPoint.setDescription("Utility/ESP specific pricing signal. Content depends on pricing signal type. When H/M/L type is specified. Low=0; Med=1; High=2.");
    sigDataPoint.setMandatory(true);
    sigDataPoint.setSize(1);
    sigDataPoint.setAddressOffset(4);
    sigDataPoint.setBlockOffset(2);
    sigDataPoint.setScaleFactorName("Sig_SF");
    sigDataPoint.setSunSpecDataType("int16");
    sigDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(sigDataPoint.name(), sigDataPoint);

    SunSpecDataPoint winTmsDataPoint;
    winTmsDataPoint.setName("WinTms");
    winTmsDataPoint.setLabel("WinTms");
    winTmsDataPoint.setDescription("Time window for charge/discharge pricing change.");
    winTmsDataPoint.setUnits("Secs");
    winTmsDataPoint.setSize(1);
    winTmsDataPoint.setAddressOffset(5);
    winTmsDataPoint.setBlockOffset(3);
    winTmsDataPoint.setSunSpecDataType("uint16");
    winTmsDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(winTmsDataPoint.name(), winTmsDataPoint);

    SunSpecDataPoint rvtTmsDataPoint;
    rvtTmsDataPoint.setName("RvtTms");
    rvtTmsDataPoint.setLabel("RvtTms");
    rvtTmsDataPoint.setDescription("Timeout period for charge/discharge pricing change.");
    rvtTmsDataPoint.setUnits("Secs");
    rvtTmsDataPoint.setSize(1);
    rvtTmsDataPoint.setAddressOffset(6);
    rvtTmsDataPoint.setBlockOffset(4);
    rvtTmsDataPoint.setSunSpecDataType("uint16");
    rvtTmsDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(rvtTmsDataPoint.name(), rvtTmsDataPoint);

    SunSpecDataPoint rmpTmsDataPoint;
    rmpTmsDataPoint.setName("RmpTms");
    rmpTmsDataPoint.setLabel("RmpTms");
    rmpTmsDataPoint.setDescription("Ramp time for moving from current charge or discharge level to new level.");
    rmpTmsDataPoint.setUnits("Secs");
    rmpTmsDataPoint.setSize(1);
    rmpTmsDataPoint.setAddressOffset(7);
    rmpTmsDataPoint.setBlockOffset(5);
    rmpTmsDataPoint.setSunSpecDataType("uint16");
    rmpTmsDataPoint.setAccess(SunSpecDataPoint::AccessReadWrite);
    m_dataPoints.insert(rmpTmsDataPoint.name(), rmpTmsDataPoint);

    SunSpecDataPoint sigSfDataPoint;
    sigSfDataPoint.setName("Sig_SF");
    sigSfDataPoint.setLabel("Sig_SF");
    sigSfDataPoint.setDescription("Pricing signal scale factor.");
    sigSfDataPoint.setMandatory(true);
    sigSfDataPoint.setSize(1);
    sigSfDataPoint.setAddressOffset(8);
    sigSfDataPoint.setBlockOffset(6);
    sigSfDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(sigSfDataPoint.name(), sigSfDataPoint);

    SunSpecDataPoint padDataPoint;
    padDataPoint.setName("Pad");
    padDataPoint.setSize(1);
    padDataPoint.setAddressOffset(9);
    padDataPoint.setBlockOffset(7);
    padDataPoint.setSunSpecDataType("pad");
    m_dataPoints.insert(padDataPoint.name(), padDataPoint);

}

QDebug operator<<(QDebug debug, SunSpecPricingModel *model)
{
    debug.nospace().noquote() << "SunSpecPricingModel(Model: " << model->modelId() << ", Register: " << model->modbusStartRegister() << ", Length: " << model->modelLength() << ")" << endl;
    if (model->dataPoints().value("ModEna").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("ModEna") << "--> " << model->modEna() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("ModEna") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("SigType").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("SigType") << "--> " << model->sigType() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("SigType") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Sig").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Sig") << "--> " << model->sig() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Sig") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("WinTms").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WinTms") << "--> " << model->winTms() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WinTms") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("RvtTms").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("RvtTms") << "--> " << model->rvtTms() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("RvtTms") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("RmpTms").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("RmpTms") << "--> " << model->rmpTms() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("RmpTms") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Pad").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Pad") << "--> " << model->pad() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Pad") << "--> NaN" << endl;
    }


    return debug.space().quote();
}
