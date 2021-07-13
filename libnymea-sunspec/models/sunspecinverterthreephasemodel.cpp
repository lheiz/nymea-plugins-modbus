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

#include "sunspecinverterthreephasemodel.h"
#include "sunspecconnection.h"

SunSpecInverterThreePhaseModel::SunSpecInverterThreePhaseModel(SunSpecConnection *connection, quint16 modbusStartRegister, quint16 length, QObject *parent) :
    SunSpecModel(connection, modbusStartRegister, 103, 50, parent)
{
    //Q_ASSERT_X(length == 50,  "SunSpecInverterThreePhaseModel", QString("model length %1 given in the constructor does not match the model length from the specs %2.").arg(length).arg(modelLength()).toLatin1());
    Q_UNUSED(length)
    initDataPoints();
}

SunSpecInverterThreePhaseModel::~SunSpecInverterThreePhaseModel()
{

}

QString SunSpecInverterThreePhaseModel::name() const
{
    return "inverter";
}

QString SunSpecInverterThreePhaseModel::description() const
{
    return "Include this model for three phase inverter monitoring";
}

QString SunSpecInverterThreePhaseModel::label() const
{
    return "Inverter (Three Phase)";
}

float SunSpecInverterThreePhaseModel::amps() const
{
    return m_amps;
}
float SunSpecInverterThreePhaseModel::ampsPhaseA() const
{
    return m_ampsPhaseA;
}
float SunSpecInverterThreePhaseModel::ampsPhaseB() const
{
    return m_ampsPhaseB;
}
float SunSpecInverterThreePhaseModel::ampsPhaseC() const
{
    return m_ampsPhaseC;
}
float SunSpecInverterThreePhaseModel::phaseVoltageAb() const
{
    return m_phaseVoltageAb;
}
float SunSpecInverterThreePhaseModel::phaseVoltageBc() const
{
    return m_phaseVoltageBc;
}
float SunSpecInverterThreePhaseModel::phaseVoltageCa() const
{
    return m_phaseVoltageCa;
}
float SunSpecInverterThreePhaseModel::phaseVoltageAn() const
{
    return m_phaseVoltageAn;
}
float SunSpecInverterThreePhaseModel::phaseVoltageBn() const
{
    return m_phaseVoltageBn;
}
float SunSpecInverterThreePhaseModel::phaseVoltageCn() const
{
    return m_phaseVoltageCn;
}
float SunSpecInverterThreePhaseModel::watts() const
{
    return m_watts;
}
float SunSpecInverterThreePhaseModel::hz() const
{
    return m_hz;
}
float SunSpecInverterThreePhaseModel::va() const
{
    return m_va;
}
float SunSpecInverterThreePhaseModel::vAr() const
{
    return m_vAr;
}
float SunSpecInverterThreePhaseModel::pf() const
{
    return m_pf;
}
quint32 SunSpecInverterThreePhaseModel::wattHours() const
{
    return m_wattHours;
}
float SunSpecInverterThreePhaseModel::dcAmps() const
{
    return m_dcAmps;
}
float SunSpecInverterThreePhaseModel::dcVoltage() const
{
    return m_dcVoltage;
}
float SunSpecInverterThreePhaseModel::dcWatts() const
{
    return m_dcWatts;
}
float SunSpecInverterThreePhaseModel::cabinetTemperature() const
{
    return m_cabinetTemperature;
}
float SunSpecInverterThreePhaseModel::heatSinkTemperature() const
{
    return m_heatSinkTemperature;
}
float SunSpecInverterThreePhaseModel::transformerTemperature() const
{
    return m_transformerTemperature;
}
float SunSpecInverterThreePhaseModel::otherTemperature() const
{
    return m_otherTemperature;
}
SunSpecInverterThreePhaseModel::St SunSpecInverterThreePhaseModel::operatingState() const
{
    return m_operatingState;
}
quint16 SunSpecInverterThreePhaseModel::vendorOperatingState() const
{
    return m_vendorOperatingState;
}
SunSpecInverterThreePhaseModel::Evt1Flags SunSpecInverterThreePhaseModel::event1() const
{
    return m_event1;
}
quint32 SunSpecInverterThreePhaseModel::eventBitfield2() const
{
    return m_eventBitfield2;
}
quint32 SunSpecInverterThreePhaseModel::vendorEventBitfield1() const
{
    return m_vendorEventBitfield1;
}
quint32 SunSpecInverterThreePhaseModel::vendorEventBitfield2() const
{
    return m_vendorEventBitfield2;
}
quint32 SunSpecInverterThreePhaseModel::vendorEventBitfield3() const
{
    return m_vendorEventBitfield3;
}
quint32 SunSpecInverterThreePhaseModel::vendorEventBitfield4() const
{
    return m_vendorEventBitfield4;
}
void SunSpecInverterThreePhaseModel::processBlockData()
{
    // Scale factors
    if (m_dataPoints.value("A_SF").isValid())
        m_a_SF = m_dataPoints.value("A_SF").toInt16();

    if (m_dataPoints.value("V_SF").isValid())
        m_v_SF = m_dataPoints.value("V_SF").toInt16();

    if (m_dataPoints.value("W_SF").isValid())
        m_w_SF = m_dataPoints.value("W_SF").toInt16();

    if (m_dataPoints.value("Hz_SF").isValid())
        m_hz_SF = m_dataPoints.value("Hz_SF").toInt16();

    if (m_dataPoints.value("VA_SF").isValid())
        m_vA_SF = m_dataPoints.value("VA_SF").toInt16();

    if (m_dataPoints.value("VAr_SF").isValid())
        m_vAr_SF = m_dataPoints.value("VAr_SF").toInt16();

    if (m_dataPoints.value("PF_SF").isValid())
        m_pF_SF = m_dataPoints.value("PF_SF").toInt16();

    if (m_dataPoints.value("WH_SF").isValid())
        m_wH_SF = m_dataPoints.value("WH_SF").toInt16();

    if (m_dataPoints.value("DCA_SF").isValid())
        m_dCA_SF = m_dataPoints.value("DCA_SF").toInt16();

    if (m_dataPoints.value("DCV_SF").isValid())
        m_dCV_SF = m_dataPoints.value("DCV_SF").toInt16();

    if (m_dataPoints.value("DCW_SF").isValid())
        m_dCW_SF = m_dataPoints.value("DCW_SF").toInt16();

    if (m_dataPoints.value("Tmp_SF").isValid())
        m_tmp_SF = m_dataPoints.value("Tmp_SF").toInt16();


    // Update properties according to the data point type
    if (m_dataPoints.value("A").isValid())
        m_amps = m_dataPoints.value("A").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphA").isValid())
        m_ampsPhaseA = m_dataPoints.value("AphA").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphB").isValid())
        m_ampsPhaseB = m_dataPoints.value("AphB").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphC").isValid())
        m_ampsPhaseC = m_dataPoints.value("AphC").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("PPVphAB").isValid())
        m_phaseVoltageAb = m_dataPoints.value("PPVphAB").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPVphBC").isValid())
        m_phaseVoltageBc = m_dataPoints.value("PPVphBC").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPVphCA").isValid())
        m_phaseVoltageCa = m_dataPoints.value("PPVphCA").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphA").isValid())
        m_phaseVoltageAn = m_dataPoints.value("PhVphA").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphB").isValid())
        m_phaseVoltageBn = m_dataPoints.value("PhVphB").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphC").isValid())
        m_phaseVoltageCn = m_dataPoints.value("PhVphC").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("W").isValid())
        m_watts = m_dataPoints.value("W").toFloatWithSSF(m_w_SF);

    if (m_dataPoints.value("Hz").isValid())
        m_hz = m_dataPoints.value("Hz").toFloatWithSSF(m_hz_SF);

    if (m_dataPoints.value("VA").isValid())
        m_va = m_dataPoints.value("VA").toFloatWithSSF(m_vA_SF);

    if (m_dataPoints.value("VAr").isValid())
        m_vAr = m_dataPoints.value("VAr").toFloatWithSSF(m_vAr_SF);

    if (m_dataPoints.value("PF").isValid())
        m_pf = m_dataPoints.value("PF").toFloatWithSSF(m_pF_SF);

    if (m_dataPoints.value("WH").isValid())
        m_wattHours = m_dataPoints.value("WH").toFloatWithSSF(m_wH_SF);

    if (m_dataPoints.value("DCA").isValid())
        m_dcAmps = m_dataPoints.value("DCA").toFloatWithSSF(m_dCA_SF);

    if (m_dataPoints.value("DCV").isValid())
        m_dcVoltage = m_dataPoints.value("DCV").toFloatWithSSF(m_dCV_SF);

    if (m_dataPoints.value("DCW").isValid())
        m_dcWatts = m_dataPoints.value("DCW").toFloatWithSSF(m_dCW_SF);

    if (m_dataPoints.value("TmpCab").isValid())
        m_cabinetTemperature = m_dataPoints.value("TmpCab").toFloatWithSSF(m_tmp_SF);

    if (m_dataPoints.value("TmpSnk").isValid())
        m_heatSinkTemperature = m_dataPoints.value("TmpSnk").toFloatWithSSF(m_tmp_SF);

    if (m_dataPoints.value("TmpTrns").isValid())
        m_transformerTemperature = m_dataPoints.value("TmpTrns").toFloatWithSSF(m_tmp_SF);

    if (m_dataPoints.value("TmpOt").isValid())
        m_otherTemperature = m_dataPoints.value("TmpOt").toFloatWithSSF(m_tmp_SF);

    if (m_dataPoints.value("St").isValid())
        m_operatingState = static_cast<St>(m_dataPoints.value("St").toUInt16());

    if (m_dataPoints.value("StVnd").isValid())
        m_vendorOperatingState = m_dataPoints.value("StVnd").toUInt16();

    if (m_dataPoints.value("Evt1").isValid())
        m_event1 = static_cast<Evt1Flags>(m_dataPoints.value("Evt1").toUInt32());

    if (m_dataPoints.value("Evt2").isValid())
        m_eventBitfield2 = m_dataPoints.value("Evt2").toUInt32();

    if (m_dataPoints.value("EvtVnd1").isValid())
        m_vendorEventBitfield1 = m_dataPoints.value("EvtVnd1").toUInt32();

    if (m_dataPoints.value("EvtVnd2").isValid())
        m_vendorEventBitfield2 = m_dataPoints.value("EvtVnd2").toUInt32();

    if (m_dataPoints.value("EvtVnd3").isValid())
        m_vendorEventBitfield3 = m_dataPoints.value("EvtVnd3").toUInt32();

    if (m_dataPoints.value("EvtVnd4").isValid())
        m_vendorEventBitfield4 = m_dataPoints.value("EvtVnd4").toUInt32();


    qCDebug(dcSunSpec()) << this;
}

void SunSpecInverterThreePhaseModel::initDataPoints()
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

    SunSpecDataPoint ampsDataPoint;
    ampsDataPoint.setName("A");
    ampsDataPoint.setLabel("Amps");
    ampsDataPoint.setDescription("AC Current");
    ampsDataPoint.setUnits("A");
    ampsDataPoint.setMandatory(true);
    ampsDataPoint.setSize(1);
    ampsDataPoint.setAddressOffset(2);
    ampsDataPoint.setBlockOffset(0);
    ampsDataPoint.setScaleFactorName("A_SF");
    ampsDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(ampsDataPoint.name(), ampsDataPoint);

    SunSpecDataPoint ampsPhaseADataPoint;
    ampsPhaseADataPoint.setName("AphA");
    ampsPhaseADataPoint.setLabel("Amps PhaseA");
    ampsPhaseADataPoint.setDescription("Phase A Current");
    ampsPhaseADataPoint.setUnits("A");
    ampsPhaseADataPoint.setMandatory(true);
    ampsPhaseADataPoint.setSize(1);
    ampsPhaseADataPoint.setAddressOffset(3);
    ampsPhaseADataPoint.setBlockOffset(1);
    ampsPhaseADataPoint.setScaleFactorName("A_SF");
    ampsPhaseADataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(ampsPhaseADataPoint.name(), ampsPhaseADataPoint);

    SunSpecDataPoint ampsPhaseBDataPoint;
    ampsPhaseBDataPoint.setName("AphB");
    ampsPhaseBDataPoint.setLabel("Amps PhaseB");
    ampsPhaseBDataPoint.setDescription("Phase B Current");
    ampsPhaseBDataPoint.setUnits("A");
    ampsPhaseBDataPoint.setMandatory(true);
    ampsPhaseBDataPoint.setSize(1);
    ampsPhaseBDataPoint.setAddressOffset(4);
    ampsPhaseBDataPoint.setBlockOffset(2);
    ampsPhaseBDataPoint.setScaleFactorName("A_SF");
    ampsPhaseBDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(ampsPhaseBDataPoint.name(), ampsPhaseBDataPoint);

    SunSpecDataPoint ampsPhaseCDataPoint;
    ampsPhaseCDataPoint.setName("AphC");
    ampsPhaseCDataPoint.setLabel("Amps PhaseC");
    ampsPhaseCDataPoint.setDescription("Phase C Current");
    ampsPhaseCDataPoint.setUnits("A");
    ampsPhaseCDataPoint.setMandatory(true);
    ampsPhaseCDataPoint.setSize(1);
    ampsPhaseCDataPoint.setAddressOffset(5);
    ampsPhaseCDataPoint.setBlockOffset(3);
    ampsPhaseCDataPoint.setScaleFactorName("A_SF");
    ampsPhaseCDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(ampsPhaseCDataPoint.name(), ampsPhaseCDataPoint);

    SunSpecDataPoint a_SFDataPoint;
    a_SFDataPoint.setName("A_SF");
    a_SFDataPoint.setMandatory(true);
    a_SFDataPoint.setSize(1);
    a_SFDataPoint.setAddressOffset(6);
    a_SFDataPoint.setBlockOffset(4);
    a_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(a_SFDataPoint.name(), a_SFDataPoint);

    SunSpecDataPoint phaseVoltageAbDataPoint;
    phaseVoltageAbDataPoint.setName("PPVphAB");
    phaseVoltageAbDataPoint.setLabel("Phase Voltage AB");
    phaseVoltageAbDataPoint.setDescription("Phase Voltage AB");
    phaseVoltageAbDataPoint.setUnits("V");
    phaseVoltageAbDataPoint.setSize(1);
    phaseVoltageAbDataPoint.setAddressOffset(7);
    phaseVoltageAbDataPoint.setBlockOffset(5);
    phaseVoltageAbDataPoint.setScaleFactorName("V_SF");
    phaseVoltageAbDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageAbDataPoint.name(), phaseVoltageAbDataPoint);

    SunSpecDataPoint phaseVoltageBcDataPoint;
    phaseVoltageBcDataPoint.setName("PPVphBC");
    phaseVoltageBcDataPoint.setLabel("Phase Voltage BC");
    phaseVoltageBcDataPoint.setDescription("Phase Voltage BC");
    phaseVoltageBcDataPoint.setUnits("V");
    phaseVoltageBcDataPoint.setSize(1);
    phaseVoltageBcDataPoint.setAddressOffset(8);
    phaseVoltageBcDataPoint.setBlockOffset(6);
    phaseVoltageBcDataPoint.setScaleFactorName("V_SF");
    phaseVoltageBcDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageBcDataPoint.name(), phaseVoltageBcDataPoint);

    SunSpecDataPoint phaseVoltageCaDataPoint;
    phaseVoltageCaDataPoint.setName("PPVphCA");
    phaseVoltageCaDataPoint.setLabel("Phase Voltage CA");
    phaseVoltageCaDataPoint.setDescription("Phase Voltage CA");
    phaseVoltageCaDataPoint.setUnits("V");
    phaseVoltageCaDataPoint.setSize(1);
    phaseVoltageCaDataPoint.setAddressOffset(9);
    phaseVoltageCaDataPoint.setBlockOffset(7);
    phaseVoltageCaDataPoint.setScaleFactorName("V_SF");
    phaseVoltageCaDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageCaDataPoint.name(), phaseVoltageCaDataPoint);

    SunSpecDataPoint phaseVoltageAnDataPoint;
    phaseVoltageAnDataPoint.setName("PhVphA");
    phaseVoltageAnDataPoint.setLabel("Phase Voltage AN");
    phaseVoltageAnDataPoint.setDescription("Phase Voltage AN");
    phaseVoltageAnDataPoint.setUnits("V");
    phaseVoltageAnDataPoint.setMandatory(true);
    phaseVoltageAnDataPoint.setSize(1);
    phaseVoltageAnDataPoint.setAddressOffset(10);
    phaseVoltageAnDataPoint.setBlockOffset(8);
    phaseVoltageAnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageAnDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageAnDataPoint.name(), phaseVoltageAnDataPoint);

    SunSpecDataPoint phaseVoltageBnDataPoint;
    phaseVoltageBnDataPoint.setName("PhVphB");
    phaseVoltageBnDataPoint.setLabel("Phase Voltage BN");
    phaseVoltageBnDataPoint.setDescription("Phase Voltage BN");
    phaseVoltageBnDataPoint.setUnits("V");
    phaseVoltageBnDataPoint.setMandatory(true);
    phaseVoltageBnDataPoint.setSize(1);
    phaseVoltageBnDataPoint.setAddressOffset(11);
    phaseVoltageBnDataPoint.setBlockOffset(9);
    phaseVoltageBnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageBnDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageBnDataPoint.name(), phaseVoltageBnDataPoint);

    SunSpecDataPoint phaseVoltageCnDataPoint;
    phaseVoltageCnDataPoint.setName("PhVphC");
    phaseVoltageCnDataPoint.setLabel("Phase Voltage CN");
    phaseVoltageCnDataPoint.setDescription("Phase Voltage CN");
    phaseVoltageCnDataPoint.setUnits("V");
    phaseVoltageCnDataPoint.setMandatory(true);
    phaseVoltageCnDataPoint.setSize(1);
    phaseVoltageCnDataPoint.setAddressOffset(12);
    phaseVoltageCnDataPoint.setBlockOffset(10);
    phaseVoltageCnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageCnDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(phaseVoltageCnDataPoint.name(), phaseVoltageCnDataPoint);

    SunSpecDataPoint v_SFDataPoint;
    v_SFDataPoint.setName("V_SF");
    v_SFDataPoint.setMandatory(true);
    v_SFDataPoint.setSize(1);
    v_SFDataPoint.setAddressOffset(13);
    v_SFDataPoint.setBlockOffset(11);
    v_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(v_SFDataPoint.name(), v_SFDataPoint);

    SunSpecDataPoint wattsDataPoint;
    wattsDataPoint.setName("W");
    wattsDataPoint.setLabel("Watts");
    wattsDataPoint.setDescription("AC Power");
    wattsDataPoint.setUnits("W");
    wattsDataPoint.setMandatory(true);
    wattsDataPoint.setSize(1);
    wattsDataPoint.setAddressOffset(14);
    wattsDataPoint.setBlockOffset(12);
    wattsDataPoint.setScaleFactorName("W_SF");
    wattsDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(wattsDataPoint.name(), wattsDataPoint);

    SunSpecDataPoint w_SFDataPoint;
    w_SFDataPoint.setName("W_SF");
    w_SFDataPoint.setMandatory(true);
    w_SFDataPoint.setSize(1);
    w_SFDataPoint.setAddressOffset(15);
    w_SFDataPoint.setBlockOffset(13);
    w_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(w_SFDataPoint.name(), w_SFDataPoint);

    SunSpecDataPoint hzDataPoint;
    hzDataPoint.setName("Hz");
    hzDataPoint.setLabel("Hz");
    hzDataPoint.setDescription("Line Frequency");
    hzDataPoint.setUnits("Hz");
    hzDataPoint.setMandatory(true);
    hzDataPoint.setSize(1);
    hzDataPoint.setAddressOffset(16);
    hzDataPoint.setBlockOffset(14);
    hzDataPoint.setScaleFactorName("Hz_SF");
    hzDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(hzDataPoint.name(), hzDataPoint);

    SunSpecDataPoint hz_SFDataPoint;
    hz_SFDataPoint.setName("Hz_SF");
    hz_SFDataPoint.setMandatory(true);
    hz_SFDataPoint.setSize(1);
    hz_SFDataPoint.setAddressOffset(17);
    hz_SFDataPoint.setBlockOffset(15);
    hz_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(hz_SFDataPoint.name(), hz_SFDataPoint);

    SunSpecDataPoint vaDataPoint;
    vaDataPoint.setName("VA");
    vaDataPoint.setLabel("VA");
    vaDataPoint.setDescription("AC Apparent Power");
    vaDataPoint.setUnits("VA");
    vaDataPoint.setSize(1);
    vaDataPoint.setAddressOffset(18);
    vaDataPoint.setBlockOffset(16);
    vaDataPoint.setScaleFactorName("VA_SF");
    vaDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vaDataPoint.name(), vaDataPoint);

    SunSpecDataPoint vA_SFDataPoint;
    vA_SFDataPoint.setName("VA_SF");
    vA_SFDataPoint.setSize(1);
    vA_SFDataPoint.setAddressOffset(19);
    vA_SFDataPoint.setBlockOffset(17);
    vA_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(vA_SFDataPoint.name(), vA_SFDataPoint);

    SunSpecDataPoint vArDataPoint;
    vArDataPoint.setName("VAr");
    vArDataPoint.setLabel("VAr");
    vArDataPoint.setDescription("AC Reactive Power");
    vArDataPoint.setUnits("var");
    vArDataPoint.setSize(1);
    vArDataPoint.setAddressOffset(20);
    vArDataPoint.setBlockOffset(18);
    vArDataPoint.setScaleFactorName("VAr_SF");
    vArDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vArDataPoint.name(), vArDataPoint);

    SunSpecDataPoint vAr_SFDataPoint;
    vAr_SFDataPoint.setName("VAr_SF");
    vAr_SFDataPoint.setSize(1);
    vAr_SFDataPoint.setAddressOffset(21);
    vAr_SFDataPoint.setBlockOffset(19);
    vAr_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(vAr_SFDataPoint.name(), vAr_SFDataPoint);

    SunSpecDataPoint pfDataPoint;
    pfDataPoint.setName("PF");
    pfDataPoint.setLabel("PF");
    pfDataPoint.setDescription("AC Power Factor");
    pfDataPoint.setUnits("Pct");
    pfDataPoint.setSize(1);
    pfDataPoint.setAddressOffset(22);
    pfDataPoint.setBlockOffset(20);
    pfDataPoint.setScaleFactorName("PF_SF");
    pfDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(pfDataPoint.name(), pfDataPoint);

    SunSpecDataPoint pF_SFDataPoint;
    pF_SFDataPoint.setName("PF_SF");
    pF_SFDataPoint.setSize(1);
    pF_SFDataPoint.setAddressOffset(23);
    pF_SFDataPoint.setBlockOffset(21);
    pF_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(pF_SFDataPoint.name(), pF_SFDataPoint);

    SunSpecDataPoint wattHoursDataPoint;
    wattHoursDataPoint.setName("WH");
    wattHoursDataPoint.setLabel("WattHours");
    wattHoursDataPoint.setDescription("AC Energy");
    wattHoursDataPoint.setUnits("Wh");
    wattHoursDataPoint.setMandatory(true);
    wattHoursDataPoint.setSize(2);
    wattHoursDataPoint.setAddressOffset(24);
    wattHoursDataPoint.setBlockOffset(22);
    wattHoursDataPoint.setScaleFactorName("WH_SF");
    wattHoursDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(wattHoursDataPoint.name(), wattHoursDataPoint);

    SunSpecDataPoint wH_SFDataPoint;
    wH_SFDataPoint.setName("WH_SF");
    wH_SFDataPoint.setMandatory(true);
    wH_SFDataPoint.setSize(1);
    wH_SFDataPoint.setAddressOffset(26);
    wH_SFDataPoint.setBlockOffset(24);
    wH_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(wH_SFDataPoint.name(), wH_SFDataPoint);

    SunSpecDataPoint dcAmpsDataPoint;
    dcAmpsDataPoint.setName("DCA");
    dcAmpsDataPoint.setLabel("DC Amps");
    dcAmpsDataPoint.setDescription("DC Current");
    dcAmpsDataPoint.setUnits("A");
    dcAmpsDataPoint.setSize(1);
    dcAmpsDataPoint.setAddressOffset(27);
    dcAmpsDataPoint.setBlockOffset(25);
    dcAmpsDataPoint.setScaleFactorName("DCA_SF");
    dcAmpsDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(dcAmpsDataPoint.name(), dcAmpsDataPoint);

    SunSpecDataPoint dCA_SFDataPoint;
    dCA_SFDataPoint.setName("DCA_SF");
    dCA_SFDataPoint.setSize(1);
    dCA_SFDataPoint.setAddressOffset(28);
    dCA_SFDataPoint.setBlockOffset(26);
    dCA_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(dCA_SFDataPoint.name(), dCA_SFDataPoint);

    SunSpecDataPoint dcVoltageDataPoint;
    dcVoltageDataPoint.setName("DCV");
    dcVoltageDataPoint.setLabel("DC Voltage");
    dcVoltageDataPoint.setDescription("DC Voltage");
    dcVoltageDataPoint.setUnits("V");
    dcVoltageDataPoint.setSize(1);
    dcVoltageDataPoint.setAddressOffset(29);
    dcVoltageDataPoint.setBlockOffset(27);
    dcVoltageDataPoint.setScaleFactorName("DCV_SF");
    dcVoltageDataPoint.setSunSpecDataType("uint16");
    m_dataPoints.insert(dcVoltageDataPoint.name(), dcVoltageDataPoint);

    SunSpecDataPoint dCV_SFDataPoint;
    dCV_SFDataPoint.setName("DCV_SF");
    dCV_SFDataPoint.setSize(1);
    dCV_SFDataPoint.setAddressOffset(30);
    dCV_SFDataPoint.setBlockOffset(28);
    dCV_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(dCV_SFDataPoint.name(), dCV_SFDataPoint);

    SunSpecDataPoint dcWattsDataPoint;
    dcWattsDataPoint.setName("DCW");
    dcWattsDataPoint.setLabel("DC Watts");
    dcWattsDataPoint.setDescription("DC Power");
    dcWattsDataPoint.setUnits("W");
    dcWattsDataPoint.setSize(1);
    dcWattsDataPoint.setAddressOffset(31);
    dcWattsDataPoint.setBlockOffset(29);
    dcWattsDataPoint.setScaleFactorName("DCW_SF");
    dcWattsDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(dcWattsDataPoint.name(), dcWattsDataPoint);

    SunSpecDataPoint dCW_SFDataPoint;
    dCW_SFDataPoint.setName("DCW_SF");
    dCW_SFDataPoint.setSize(1);
    dCW_SFDataPoint.setAddressOffset(32);
    dCW_SFDataPoint.setBlockOffset(30);
    dCW_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(dCW_SFDataPoint.name(), dCW_SFDataPoint);

    SunSpecDataPoint cabinetTemperatureDataPoint;
    cabinetTemperatureDataPoint.setName("TmpCab");
    cabinetTemperatureDataPoint.setLabel("Cabinet Temperature");
    cabinetTemperatureDataPoint.setDescription("Cabinet Temperature");
    cabinetTemperatureDataPoint.setUnits("C");
    cabinetTemperatureDataPoint.setMandatory(true);
    cabinetTemperatureDataPoint.setSize(1);
    cabinetTemperatureDataPoint.setAddressOffset(33);
    cabinetTemperatureDataPoint.setBlockOffset(31);
    cabinetTemperatureDataPoint.setScaleFactorName("Tmp_SF");
    cabinetTemperatureDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(cabinetTemperatureDataPoint.name(), cabinetTemperatureDataPoint);

    SunSpecDataPoint heatSinkTemperatureDataPoint;
    heatSinkTemperatureDataPoint.setName("TmpSnk");
    heatSinkTemperatureDataPoint.setLabel("Heat Sink Temperature");
    heatSinkTemperatureDataPoint.setDescription("Heat Sink Temperature");
    heatSinkTemperatureDataPoint.setUnits("C");
    heatSinkTemperatureDataPoint.setSize(1);
    heatSinkTemperatureDataPoint.setAddressOffset(34);
    heatSinkTemperatureDataPoint.setBlockOffset(32);
    heatSinkTemperatureDataPoint.setScaleFactorName("Tmp_SF");
    heatSinkTemperatureDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(heatSinkTemperatureDataPoint.name(), heatSinkTemperatureDataPoint);

    SunSpecDataPoint transformerTemperatureDataPoint;
    transformerTemperatureDataPoint.setName("TmpTrns");
    transformerTemperatureDataPoint.setLabel("Transformer Temperature");
    transformerTemperatureDataPoint.setDescription("Transformer Temperature");
    transformerTemperatureDataPoint.setUnits("C");
    transformerTemperatureDataPoint.setSize(1);
    transformerTemperatureDataPoint.setAddressOffset(35);
    transformerTemperatureDataPoint.setBlockOffset(33);
    transformerTemperatureDataPoint.setScaleFactorName("Tmp_SF");
    transformerTemperatureDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(transformerTemperatureDataPoint.name(), transformerTemperatureDataPoint);

    SunSpecDataPoint otherTemperatureDataPoint;
    otherTemperatureDataPoint.setName("TmpOt");
    otherTemperatureDataPoint.setLabel("Other Temperature");
    otherTemperatureDataPoint.setDescription("Other Temperature");
    otherTemperatureDataPoint.setUnits("C");
    otherTemperatureDataPoint.setSize(1);
    otherTemperatureDataPoint.setAddressOffset(36);
    otherTemperatureDataPoint.setBlockOffset(34);
    otherTemperatureDataPoint.setScaleFactorName("Tmp_SF");
    otherTemperatureDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(otherTemperatureDataPoint.name(), otherTemperatureDataPoint);

    SunSpecDataPoint tmp_SFDataPoint;
    tmp_SFDataPoint.setName("Tmp_SF");
    tmp_SFDataPoint.setMandatory(true);
    tmp_SFDataPoint.setSize(1);
    tmp_SFDataPoint.setAddressOffset(37);
    tmp_SFDataPoint.setBlockOffset(35);
    tmp_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(tmp_SFDataPoint.name(), tmp_SFDataPoint);

    SunSpecDataPoint operatingStateDataPoint;
    operatingStateDataPoint.setName("St");
    operatingStateDataPoint.setLabel("Operating State");
    operatingStateDataPoint.setDescription("Enumerated value.  Operating state");
    operatingStateDataPoint.setMandatory(true);
    operatingStateDataPoint.setSize(1);
    operatingStateDataPoint.setAddressOffset(38);
    operatingStateDataPoint.setBlockOffset(36);
    operatingStateDataPoint.setSunSpecDataType("enum16");
    m_dataPoints.insert(operatingStateDataPoint.name(), operatingStateDataPoint);

    SunSpecDataPoint vendorOperatingStateDataPoint;
    vendorOperatingStateDataPoint.setName("StVnd");
    vendorOperatingStateDataPoint.setLabel("Vendor Operating State");
    vendorOperatingStateDataPoint.setDescription("Vendor specific operating state code");
    vendorOperatingStateDataPoint.setSize(1);
    vendorOperatingStateDataPoint.setAddressOffset(39);
    vendorOperatingStateDataPoint.setBlockOffset(37);
    vendorOperatingStateDataPoint.setSunSpecDataType("enum16");
    m_dataPoints.insert(vendorOperatingStateDataPoint.name(), vendorOperatingStateDataPoint);

    SunSpecDataPoint event1DataPoint;
    event1DataPoint.setName("Evt1");
    event1DataPoint.setLabel("Event1");
    event1DataPoint.setDescription("Bitmask value. Event fields");
    event1DataPoint.setMandatory(true);
    event1DataPoint.setSize(2);
    event1DataPoint.setAddressOffset(40);
    event1DataPoint.setBlockOffset(38);
    event1DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(event1DataPoint.name(), event1DataPoint);

    SunSpecDataPoint eventBitfield2DataPoint;
    eventBitfield2DataPoint.setName("Evt2");
    eventBitfield2DataPoint.setLabel("Event Bitfield 2");
    eventBitfield2DataPoint.setDescription("Reserved for future use");
    eventBitfield2DataPoint.setMandatory(true);
    eventBitfield2DataPoint.setSize(2);
    eventBitfield2DataPoint.setAddressOffset(42);
    eventBitfield2DataPoint.setBlockOffset(40);
    eventBitfield2DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(eventBitfield2DataPoint.name(), eventBitfield2DataPoint);

    SunSpecDataPoint vendorEventBitfield1DataPoint;
    vendorEventBitfield1DataPoint.setName("EvtVnd1");
    vendorEventBitfield1DataPoint.setLabel("Vendor Event Bitfield 1");
    vendorEventBitfield1DataPoint.setDescription("Vendor defined events");
    vendorEventBitfield1DataPoint.setSize(2);
    vendorEventBitfield1DataPoint.setAddressOffset(44);
    vendorEventBitfield1DataPoint.setBlockOffset(42);
    vendorEventBitfield1DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(vendorEventBitfield1DataPoint.name(), vendorEventBitfield1DataPoint);

    SunSpecDataPoint vendorEventBitfield2DataPoint;
    vendorEventBitfield2DataPoint.setName("EvtVnd2");
    vendorEventBitfield2DataPoint.setLabel("Vendor Event Bitfield 2");
    vendorEventBitfield2DataPoint.setDescription("Vendor defined events");
    vendorEventBitfield2DataPoint.setSize(2);
    vendorEventBitfield2DataPoint.setAddressOffset(46);
    vendorEventBitfield2DataPoint.setBlockOffset(44);
    vendorEventBitfield2DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(vendorEventBitfield2DataPoint.name(), vendorEventBitfield2DataPoint);

    SunSpecDataPoint vendorEventBitfield3DataPoint;
    vendorEventBitfield3DataPoint.setName("EvtVnd3");
    vendorEventBitfield3DataPoint.setLabel("Vendor Event Bitfield 3");
    vendorEventBitfield3DataPoint.setDescription("Vendor defined events");
    vendorEventBitfield3DataPoint.setSize(2);
    vendorEventBitfield3DataPoint.setAddressOffset(48);
    vendorEventBitfield3DataPoint.setBlockOffset(46);
    vendorEventBitfield3DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(vendorEventBitfield3DataPoint.name(), vendorEventBitfield3DataPoint);

    SunSpecDataPoint vendorEventBitfield4DataPoint;
    vendorEventBitfield4DataPoint.setName("EvtVnd4");
    vendorEventBitfield4DataPoint.setLabel("Vendor Event Bitfield 4");
    vendorEventBitfield4DataPoint.setDescription("Vendor defined events");
    vendorEventBitfield4DataPoint.setSize(2);
    vendorEventBitfield4DataPoint.setAddressOffset(50);
    vendorEventBitfield4DataPoint.setBlockOffset(48);
    vendorEventBitfield4DataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(vendorEventBitfield4DataPoint.name(), vendorEventBitfield4DataPoint);

}

QDebug operator<<(QDebug debug, SunSpecInverterThreePhaseModel *model)
{
    debug.nospace().noquote() << "SunSpecInverterThreePhaseModel(Model: " << model->modelId() << ", Register: " << model->modbusStartRegister() << ", Length: " << model->modelLength() << ")" << endl;
    if (model->dataPoints().value("A").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("A") << "--> " << model->amps() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("A") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("AphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphA") << "--> " << model->ampsPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("AphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphB") << "--> " << model->ampsPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("AphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphC") << "--> " << model->ampsPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("AphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PPVphAB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphAB") << "--> " << model->phaseVoltageAb() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphAB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PPVphBC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphBC") << "--> " << model->phaseVoltageBc() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphBC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PPVphCA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphCA") << "--> " << model->phaseVoltageCa() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPVphCA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PhVphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphA") << "--> " << model->phaseVoltageAn() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PhVphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphB") << "--> " << model->phaseVoltageBn() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PhVphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphC") << "--> " << model->phaseVoltageCn() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhVphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("W").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("W") << "--> " << model->watts() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("W") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Hz").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Hz") << "--> " << model->hz() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Hz") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VA") << "--> " << model->va() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VAr").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAr") << "--> " << model->vAr() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAr") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PF").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PF") << "--> " << model->pf() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PF") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("WH").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WH") << "--> " << model->wattHours() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WH") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("DCA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCA") << "--> " << model->dcAmps() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("DCV").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCV") << "--> " << model->dcVoltage() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCV") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("DCW").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCW") << "--> " << model->dcWatts() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("DCW") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TmpCab").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpCab") << "--> " << model->cabinetTemperature() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpCab") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TmpSnk").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpSnk") << "--> " << model->heatSinkTemperature() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpSnk") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TmpTrns").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpTrns") << "--> " << model->transformerTemperature() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpTrns") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TmpOt").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpOt") << "--> " << model->otherTemperature() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TmpOt") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("St").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("St") << "--> " << model->operatingState() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("St") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("StVnd").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("StVnd") << "--> " << model->vendorOperatingState() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("StVnd") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Evt1").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt1") << "--> " << model->event1() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt1") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Evt2").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt2") << "--> " << model->eventBitfield2() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt2") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("EvtVnd1").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd1") << "--> " << model->vendorEventBitfield1() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd1") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("EvtVnd2").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd2") << "--> " << model->vendorEventBitfield2() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd2") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("EvtVnd3").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd3") << "--> " << model->vendorEventBitfield3() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd3") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("EvtVnd4").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd4") << "--> " << model->vendorEventBitfield4() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("EvtVnd4") << "--> NaN" << endl;
    }


    return debug.space().quote();
}