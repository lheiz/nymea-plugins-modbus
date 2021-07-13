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

#include "sunspecmetersinglephasemodel.h"
#include "sunspecconnection.h"

SunSpecMeterSinglePhaseModel::SunSpecMeterSinglePhaseModel(SunSpecConnection *connection, quint16 modbusStartRegister, quint16 length, QObject *parent) :
    SunSpecModel(connection, modbusStartRegister, 201, 105, parent)
{
    //Q_ASSERT_X(length == 105,  "SunSpecMeterSinglePhaseModel", QString("model length %1 given in the constructor does not match the model length from the specs %2.").arg(length).arg(modelLength()).toLatin1());
    Q_UNUSED(length)
    initDataPoints();
}

SunSpecMeterSinglePhaseModel::~SunSpecMeterSinglePhaseModel()
{

}

QString SunSpecMeterSinglePhaseModel::name() const
{
    return "ac_meter";
}

QString SunSpecMeterSinglePhaseModel::description() const
{
    return "Include this model for single phase (AN or AB) metering";
}

QString SunSpecMeterSinglePhaseModel::label() const
{
    return "Meter (Single Phase)";
}

float SunSpecMeterSinglePhaseModel::amps() const
{
    return m_amps;
}
float SunSpecMeterSinglePhaseModel::ampsPhaseA() const
{
    return m_ampsPhaseA;
}
float SunSpecMeterSinglePhaseModel::ampsPhaseB() const
{
    return m_ampsPhaseB;
}
float SunSpecMeterSinglePhaseModel::ampsPhaseC() const
{
    return m_ampsPhaseC;
}
float SunSpecMeterSinglePhaseModel::voltageLn() const
{
    return m_voltageLn;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageAn() const
{
    return m_phaseVoltageAn;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageBn() const
{
    return m_phaseVoltageBn;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageCn() const
{
    return m_phaseVoltageCn;
}
float SunSpecMeterSinglePhaseModel::voltageLl() const
{
    return m_voltageLl;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageAb() const
{
    return m_phaseVoltageAb;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageBc() const
{
    return m_phaseVoltageBc;
}
float SunSpecMeterSinglePhaseModel::phaseVoltageCa() const
{
    return m_phaseVoltageCa;
}
float SunSpecMeterSinglePhaseModel::hz() const
{
    return m_hz;
}
float SunSpecMeterSinglePhaseModel::watts() const
{
    return m_watts;
}
float SunSpecMeterSinglePhaseModel::wattsPhaseA() const
{
    return m_wattsPhaseA;
}
float SunSpecMeterSinglePhaseModel::wattsPhaseB() const
{
    return m_wattsPhaseB;
}
float SunSpecMeterSinglePhaseModel::wattsPhaseC() const
{
    return m_wattsPhaseC;
}
float SunSpecMeterSinglePhaseModel::va() const
{
    return m_va;
}
float SunSpecMeterSinglePhaseModel::vaPhaseA() const
{
    return m_vaPhaseA;
}
float SunSpecMeterSinglePhaseModel::vaPhaseB() const
{
    return m_vaPhaseB;
}
float SunSpecMeterSinglePhaseModel::vaPhaseC() const
{
    return m_vaPhaseC;
}
float SunSpecMeterSinglePhaseModel::var() const
{
    return m_var;
}
float SunSpecMeterSinglePhaseModel::varPhaseA() const
{
    return m_varPhaseA;
}
float SunSpecMeterSinglePhaseModel::varPhaseB() const
{
    return m_varPhaseB;
}
float SunSpecMeterSinglePhaseModel::varPhaseC() const
{
    return m_varPhaseC;
}
float SunSpecMeterSinglePhaseModel::pf() const
{
    return m_pf;
}
float SunSpecMeterSinglePhaseModel::pfPhaseA() const
{
    return m_pfPhaseA;
}
float SunSpecMeterSinglePhaseModel::pfPhaseB() const
{
    return m_pfPhaseB;
}
float SunSpecMeterSinglePhaseModel::pfPhaseC() const
{
    return m_pfPhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursExported() const
{
    return m_totalWattHoursExported;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursExportedPhaseA() const
{
    return m_totalWattHoursExportedPhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursExportedPhaseB() const
{
    return m_totalWattHoursExportedPhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursExportedPhaseC() const
{
    return m_totalWattHoursExportedPhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursImported() const
{
    return m_totalWattHoursImported;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursImportedPhaseA() const
{
    return m_totalWattHoursImportedPhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursImportedPhaseB() const
{
    return m_totalWattHoursImportedPhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalWattHoursImportedPhaseC() const
{
    return m_totalWattHoursImportedPhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursExported() const
{
    return m_totalVaHoursExported;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursExportedPhaseA() const
{
    return m_totalVaHoursExportedPhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursExportedPhaseB() const
{
    return m_totalVaHoursExportedPhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursExportedPhaseC() const
{
    return m_totalVaHoursExportedPhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursImported() const
{
    return m_totalVaHoursImported;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursImportedPhaseA() const
{
    return m_totalVaHoursImportedPhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursImportedPhaseB() const
{
    return m_totalVaHoursImportedPhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVaHoursImportedPhaseC() const
{
    return m_totalVaHoursImportedPhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVarHoursImportedQ1() const
{
    return m_totalVarHoursImportedQ1;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ1PhaseA() const
{
    return m_totalVArHoursImportedQ1PhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ1PhaseB() const
{
    return m_totalVArHoursImportedQ1PhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ1PhaseC() const
{
    return m_totalVArHoursImportedQ1PhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ2() const
{
    return m_totalVArHoursImportedQ2;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ2PhaseA() const
{
    return m_totalVArHoursImportedQ2PhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ2PhaseB() const
{
    return m_totalVArHoursImportedQ2PhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursImportedQ2PhaseC() const
{
    return m_totalVArHoursImportedQ2PhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ3() const
{
    return m_totalVArHoursExportedQ3;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ3PhaseA() const
{
    return m_totalVArHoursExportedQ3PhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ3PhaseB() const
{
    return m_totalVArHoursExportedQ3PhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ3PhaseC() const
{
    return m_totalVArHoursExportedQ3PhaseC;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ4() const
{
    return m_totalVArHoursExportedQ4;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ4ImportedPhaseA() const
{
    return m_totalVArHoursExportedQ4ImportedPhaseA;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ4ImportedPhaseB() const
{
    return m_totalVArHoursExportedQ4ImportedPhaseB;
}
quint32 SunSpecMeterSinglePhaseModel::totalVArHoursExportedQ4ImportedPhaseC() const
{
    return m_totalVArHoursExportedQ4ImportedPhaseC;
}
SunSpecMeterSinglePhaseModel::EvtFlags SunSpecMeterSinglePhaseModel::events() const
{
    return m_events;
}
void SunSpecMeterSinglePhaseModel::processBlockData()
{
    // Scale factors
    if (m_dataPoints.value("A_SF").isValid())
        m_a_SF = m_dataPoints.value("A_SF").toInt16();

    if (m_dataPoints.value("V_SF").isValid())
        m_v_SF = m_dataPoints.value("V_SF").toInt16();

    if (m_dataPoints.value("Hz_SF").isValid())
        m_hz_SF = m_dataPoints.value("Hz_SF").toInt16();

    if (m_dataPoints.value("W_SF").isValid())
        m_w_SF = m_dataPoints.value("W_SF").toInt16();

    if (m_dataPoints.value("VA_SF").isValid())
        m_vA_SF = m_dataPoints.value("VA_SF").toInt16();

    if (m_dataPoints.value("VAR_SF").isValid())
        m_vAR_SF = m_dataPoints.value("VAR_SF").toInt16();

    if (m_dataPoints.value("PF_SF").isValid())
        m_pF_SF = m_dataPoints.value("PF_SF").toInt16();

    if (m_dataPoints.value("TotWh_SF").isValid())
        m_totWh_SF = m_dataPoints.value("TotWh_SF").toInt16();

    if (m_dataPoints.value("TotVAh_SF").isValid())
        m_totVAh_SF = m_dataPoints.value("TotVAh_SF").toInt16();

    if (m_dataPoints.value("TotVArh_SF").isValid())
        m_totVArh_SF = m_dataPoints.value("TotVArh_SF").toInt16();


    // Update properties according to the data point type
    if (m_dataPoints.value("A").isValid())
        m_amps = m_dataPoints.value("A").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphA").isValid())
        m_ampsPhaseA = m_dataPoints.value("AphA").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphB").isValid())
        m_ampsPhaseB = m_dataPoints.value("AphB").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("AphC").isValid())
        m_ampsPhaseC = m_dataPoints.value("AphC").toFloatWithSSF(m_a_SF);

    if (m_dataPoints.value("PhV").isValid())
        m_voltageLn = m_dataPoints.value("PhV").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphA").isValid())
        m_phaseVoltageAn = m_dataPoints.value("PhVphA").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphB").isValid())
        m_phaseVoltageBn = m_dataPoints.value("PhVphB").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PhVphC").isValid())
        m_phaseVoltageCn = m_dataPoints.value("PhVphC").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPV").isValid())
        m_voltageLl = m_dataPoints.value("PPV").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPVphAB").isValid())
        m_phaseVoltageAb = m_dataPoints.value("PPVphAB").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPVphBC").isValid())
        m_phaseVoltageBc = m_dataPoints.value("PPVphBC").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("PPVphCA").isValid())
        m_phaseVoltageCa = m_dataPoints.value("PPVphCA").toFloatWithSSF(m_v_SF);

    if (m_dataPoints.value("Hz").isValid())
        m_hz = m_dataPoints.value("Hz").toFloatWithSSF(m_hz_SF);

    if (m_dataPoints.value("W").isValid())
        m_watts = m_dataPoints.value("W").toFloatWithSSF(m_w_SF);

    if (m_dataPoints.value("WphA").isValid())
        m_wattsPhaseA = m_dataPoints.value("WphA").toFloatWithSSF(m_w_SF);

    if (m_dataPoints.value("WphB").isValid())
        m_wattsPhaseB = m_dataPoints.value("WphB").toFloatWithSSF(m_w_SF);

    if (m_dataPoints.value("WphC").isValid())
        m_wattsPhaseC = m_dataPoints.value("WphC").toFloatWithSSF(m_w_SF);

    if (m_dataPoints.value("VA").isValid())
        m_va = m_dataPoints.value("VA").toFloatWithSSF(m_vA_SF);

    if (m_dataPoints.value("VAphA").isValid())
        m_vaPhaseA = m_dataPoints.value("VAphA").toFloatWithSSF(m_vA_SF);

    if (m_dataPoints.value("VAphB").isValid())
        m_vaPhaseB = m_dataPoints.value("VAphB").toFloatWithSSF(m_vA_SF);

    if (m_dataPoints.value("VAphC").isValid())
        m_vaPhaseC = m_dataPoints.value("VAphC").toFloatWithSSF(m_vA_SF);

    if (m_dataPoints.value("VAR").isValid())
        m_var = m_dataPoints.value("VAR").toFloatWithSSF(m_vAR_SF);

    if (m_dataPoints.value("VARphA").isValid())
        m_varPhaseA = m_dataPoints.value("VARphA").toFloatWithSSF(m_vAR_SF);

    if (m_dataPoints.value("VARphB").isValid())
        m_varPhaseB = m_dataPoints.value("VARphB").toFloatWithSSF(m_vAR_SF);

    if (m_dataPoints.value("VARphC").isValid())
        m_varPhaseC = m_dataPoints.value("VARphC").toFloatWithSSF(m_vAR_SF);

    if (m_dataPoints.value("PF").isValid())
        m_pf = m_dataPoints.value("PF").toFloatWithSSF(m_pF_SF);

    if (m_dataPoints.value("PFphA").isValid())
        m_pfPhaseA = m_dataPoints.value("PFphA").toFloatWithSSF(m_pF_SF);

    if (m_dataPoints.value("PFphB").isValid())
        m_pfPhaseB = m_dataPoints.value("PFphB").toFloatWithSSF(m_pF_SF);

    if (m_dataPoints.value("PFphC").isValid())
        m_pfPhaseC = m_dataPoints.value("PFphC").toFloatWithSSF(m_pF_SF);

    if (m_dataPoints.value("TotWhExp").isValid())
        m_totalWattHoursExported = m_dataPoints.value("TotWhExp").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhExpPhA").isValid())
        m_totalWattHoursExportedPhaseA = m_dataPoints.value("TotWhExpPhA").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhExpPhB").isValid())
        m_totalWattHoursExportedPhaseB = m_dataPoints.value("TotWhExpPhB").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhExpPhC").isValid())
        m_totalWattHoursExportedPhaseC = m_dataPoints.value("TotWhExpPhC").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhImp").isValid())
        m_totalWattHoursImported = m_dataPoints.value("TotWhImp").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhImpPhA").isValid())
        m_totalWattHoursImportedPhaseA = m_dataPoints.value("TotWhImpPhA").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhImpPhB").isValid())
        m_totalWattHoursImportedPhaseB = m_dataPoints.value("TotWhImpPhB").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotWhImpPhC").isValid())
        m_totalWattHoursImportedPhaseC = m_dataPoints.value("TotWhImpPhC").toFloatWithSSF(m_totWh_SF);

    if (m_dataPoints.value("TotVAhExp").isValid())
        m_totalVaHoursExported = m_dataPoints.value("TotVAhExp").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhExpPhA").isValid())
        m_totalVaHoursExportedPhaseA = m_dataPoints.value("TotVAhExpPhA").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhExpPhB").isValid())
        m_totalVaHoursExportedPhaseB = m_dataPoints.value("TotVAhExpPhB").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhExpPhC").isValid())
        m_totalVaHoursExportedPhaseC = m_dataPoints.value("TotVAhExpPhC").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhImp").isValid())
        m_totalVaHoursImported = m_dataPoints.value("TotVAhImp").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhImpPhA").isValid())
        m_totalVaHoursImportedPhaseA = m_dataPoints.value("TotVAhImpPhA").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhImpPhB").isValid())
        m_totalVaHoursImportedPhaseB = m_dataPoints.value("TotVAhImpPhB").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVAhImpPhC").isValid())
        m_totalVaHoursImportedPhaseC = m_dataPoints.value("TotVAhImpPhC").toFloatWithSSF(m_totVAh_SF);

    if (m_dataPoints.value("TotVArhImpQ1").isValid())
        m_totalVarHoursImportedQ1 = m_dataPoints.value("TotVArhImpQ1").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ1PhA").isValid())
        m_totalVArHoursImportedQ1PhaseA = m_dataPoints.value("TotVArhImpQ1PhA").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ1PhB").isValid())
        m_totalVArHoursImportedQ1PhaseB = m_dataPoints.value("TotVArhImpQ1PhB").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ1PhC").isValid())
        m_totalVArHoursImportedQ1PhaseC = m_dataPoints.value("TotVArhImpQ1PhC").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ2").isValid())
        m_totalVArHoursImportedQ2 = m_dataPoints.value("TotVArhImpQ2").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ2PhA").isValid())
        m_totalVArHoursImportedQ2PhaseA = m_dataPoints.value("TotVArhImpQ2PhA").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ2PhB").isValid())
        m_totalVArHoursImportedQ2PhaseB = m_dataPoints.value("TotVArhImpQ2PhB").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhImpQ2PhC").isValid())
        m_totalVArHoursImportedQ2PhaseC = m_dataPoints.value("TotVArhImpQ2PhC").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ3").isValid())
        m_totalVArHoursExportedQ3 = m_dataPoints.value("TotVArhExpQ3").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ3PhA").isValid())
        m_totalVArHoursExportedQ3PhaseA = m_dataPoints.value("TotVArhExpQ3PhA").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ3PhB").isValid())
        m_totalVArHoursExportedQ3PhaseB = m_dataPoints.value("TotVArhExpQ3PhB").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ3PhC").isValid())
        m_totalVArHoursExportedQ3PhaseC = m_dataPoints.value("TotVArhExpQ3PhC").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ4").isValid())
        m_totalVArHoursExportedQ4 = m_dataPoints.value("TotVArhExpQ4").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ4PhA").isValid())
        m_totalVArHoursExportedQ4ImportedPhaseA = m_dataPoints.value("TotVArhExpQ4PhA").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ4PhB").isValid())
        m_totalVArHoursExportedQ4ImportedPhaseB = m_dataPoints.value("TotVArhExpQ4PhB").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("TotVArhExpQ4PhC").isValid())
        m_totalVArHoursExportedQ4ImportedPhaseC = m_dataPoints.value("TotVArhExpQ4PhC").toFloatWithSSF(m_totVArh_SF);

    if (m_dataPoints.value("Evt").isValid())
        m_events = static_cast<EvtFlags>(m_dataPoints.value("Evt").toUInt32());


    qCDebug(dcSunSpec()) << this;
}

void SunSpecMeterSinglePhaseModel::initDataPoints()
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
    ampsDataPoint.setDescription("Total AC Current");
    ampsDataPoint.setUnits("A");
    ampsDataPoint.setMandatory(true);
    ampsDataPoint.setSize(1);
    ampsDataPoint.setAddressOffset(2);
    ampsDataPoint.setBlockOffset(0);
    ampsDataPoint.setScaleFactorName("A_SF");
    ampsDataPoint.setSunSpecDataType("int16");
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
    ampsPhaseADataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(ampsPhaseADataPoint.name(), ampsPhaseADataPoint);

    SunSpecDataPoint ampsPhaseBDataPoint;
    ampsPhaseBDataPoint.setName("AphB");
    ampsPhaseBDataPoint.setLabel("Amps PhaseB");
    ampsPhaseBDataPoint.setDescription("Phase B Current");
    ampsPhaseBDataPoint.setUnits("A");
    ampsPhaseBDataPoint.setSize(1);
    ampsPhaseBDataPoint.setAddressOffset(4);
    ampsPhaseBDataPoint.setBlockOffset(2);
    ampsPhaseBDataPoint.setScaleFactorName("A_SF");
    ampsPhaseBDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(ampsPhaseBDataPoint.name(), ampsPhaseBDataPoint);

    SunSpecDataPoint ampsPhaseCDataPoint;
    ampsPhaseCDataPoint.setName("AphC");
    ampsPhaseCDataPoint.setLabel("Amps PhaseC");
    ampsPhaseCDataPoint.setDescription("Phase C Current");
    ampsPhaseCDataPoint.setUnits("A");
    ampsPhaseCDataPoint.setSize(1);
    ampsPhaseCDataPoint.setAddressOffset(5);
    ampsPhaseCDataPoint.setBlockOffset(3);
    ampsPhaseCDataPoint.setScaleFactorName("A_SF");
    ampsPhaseCDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(ampsPhaseCDataPoint.name(), ampsPhaseCDataPoint);

    SunSpecDataPoint a_SFDataPoint;
    a_SFDataPoint.setName("A_SF");
    a_SFDataPoint.setDescription("Current scale factor");
    a_SFDataPoint.setMandatory(true);
    a_SFDataPoint.setSize(1);
    a_SFDataPoint.setAddressOffset(6);
    a_SFDataPoint.setBlockOffset(4);
    a_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(a_SFDataPoint.name(), a_SFDataPoint);

    SunSpecDataPoint voltageLnDataPoint;
    voltageLnDataPoint.setName("PhV");
    voltageLnDataPoint.setLabel("Voltage LN");
    voltageLnDataPoint.setDescription("Line to Neutral AC Voltage (average of active phases)");
    voltageLnDataPoint.setUnits("V");
    voltageLnDataPoint.setSize(1);
    voltageLnDataPoint.setAddressOffset(7);
    voltageLnDataPoint.setBlockOffset(5);
    voltageLnDataPoint.setScaleFactorName("V_SF");
    voltageLnDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(voltageLnDataPoint.name(), voltageLnDataPoint);

    SunSpecDataPoint phaseVoltageAnDataPoint;
    phaseVoltageAnDataPoint.setName("PhVphA");
    phaseVoltageAnDataPoint.setLabel("Phase Voltage AN");
    phaseVoltageAnDataPoint.setDescription("Phase Voltage AN");
    phaseVoltageAnDataPoint.setUnits("V");
    phaseVoltageAnDataPoint.setSize(1);
    phaseVoltageAnDataPoint.setAddressOffset(8);
    phaseVoltageAnDataPoint.setBlockOffset(6);
    phaseVoltageAnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageAnDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageAnDataPoint.name(), phaseVoltageAnDataPoint);

    SunSpecDataPoint phaseVoltageBnDataPoint;
    phaseVoltageBnDataPoint.setName("PhVphB");
    phaseVoltageBnDataPoint.setLabel("Phase Voltage BN");
    phaseVoltageBnDataPoint.setDescription("Phase Voltage BN");
    phaseVoltageBnDataPoint.setUnits("V");
    phaseVoltageBnDataPoint.setSize(1);
    phaseVoltageBnDataPoint.setAddressOffset(9);
    phaseVoltageBnDataPoint.setBlockOffset(7);
    phaseVoltageBnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageBnDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageBnDataPoint.name(), phaseVoltageBnDataPoint);

    SunSpecDataPoint phaseVoltageCnDataPoint;
    phaseVoltageCnDataPoint.setName("PhVphC");
    phaseVoltageCnDataPoint.setLabel("Phase Voltage CN");
    phaseVoltageCnDataPoint.setDescription("Phase Voltage CN");
    phaseVoltageCnDataPoint.setUnits("V");
    phaseVoltageCnDataPoint.setSize(1);
    phaseVoltageCnDataPoint.setAddressOffset(10);
    phaseVoltageCnDataPoint.setBlockOffset(8);
    phaseVoltageCnDataPoint.setScaleFactorName("V_SF");
    phaseVoltageCnDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageCnDataPoint.name(), phaseVoltageCnDataPoint);

    SunSpecDataPoint voltageLlDataPoint;
    voltageLlDataPoint.setName("PPV");
    voltageLlDataPoint.setLabel("Voltage LL");
    voltageLlDataPoint.setDescription("Line to Line AC Voltage (average of active phases)");
    voltageLlDataPoint.setUnits("V");
    voltageLlDataPoint.setSize(1);
    voltageLlDataPoint.setAddressOffset(11);
    voltageLlDataPoint.setBlockOffset(9);
    voltageLlDataPoint.setScaleFactorName("V_SF");
    voltageLlDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(voltageLlDataPoint.name(), voltageLlDataPoint);

    SunSpecDataPoint phaseVoltageAbDataPoint;
    phaseVoltageAbDataPoint.setName("PPVphAB");
    phaseVoltageAbDataPoint.setLabel("Phase Voltage AB");
    phaseVoltageAbDataPoint.setDescription("Phase Voltage AB");
    phaseVoltageAbDataPoint.setUnits("V");
    phaseVoltageAbDataPoint.setSize(1);
    phaseVoltageAbDataPoint.setAddressOffset(12);
    phaseVoltageAbDataPoint.setBlockOffset(10);
    phaseVoltageAbDataPoint.setScaleFactorName("V_SF");
    phaseVoltageAbDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageAbDataPoint.name(), phaseVoltageAbDataPoint);

    SunSpecDataPoint phaseVoltageBcDataPoint;
    phaseVoltageBcDataPoint.setName("PPVphBC");
    phaseVoltageBcDataPoint.setLabel("Phase Voltage BC");
    phaseVoltageBcDataPoint.setDescription("Phase Voltage BC");
    phaseVoltageBcDataPoint.setUnits("V");
    phaseVoltageBcDataPoint.setSize(1);
    phaseVoltageBcDataPoint.setAddressOffset(13);
    phaseVoltageBcDataPoint.setBlockOffset(11);
    phaseVoltageBcDataPoint.setScaleFactorName("V_SF");
    phaseVoltageBcDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageBcDataPoint.name(), phaseVoltageBcDataPoint);

    SunSpecDataPoint phaseVoltageCaDataPoint;
    phaseVoltageCaDataPoint.setName("PPVphCA");
    phaseVoltageCaDataPoint.setLabel("Phase Voltage CA");
    phaseVoltageCaDataPoint.setDescription("Phase Voltage CA");
    phaseVoltageCaDataPoint.setUnits("V");
    phaseVoltageCaDataPoint.setSize(1);
    phaseVoltageCaDataPoint.setAddressOffset(14);
    phaseVoltageCaDataPoint.setBlockOffset(12);
    phaseVoltageCaDataPoint.setScaleFactorName("V_SF");
    phaseVoltageCaDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(phaseVoltageCaDataPoint.name(), phaseVoltageCaDataPoint);

    SunSpecDataPoint v_SFDataPoint;
    v_SFDataPoint.setName("V_SF");
    v_SFDataPoint.setDescription("Voltage scale factor");
    v_SFDataPoint.setMandatory(true);
    v_SFDataPoint.setSize(1);
    v_SFDataPoint.setAddressOffset(15);
    v_SFDataPoint.setBlockOffset(13);
    v_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(v_SFDataPoint.name(), v_SFDataPoint);

    SunSpecDataPoint hzDataPoint;
    hzDataPoint.setName("Hz");
    hzDataPoint.setLabel("Hz");
    hzDataPoint.setDescription("Frequency");
    hzDataPoint.setUnits("Hz");
    hzDataPoint.setMandatory(true);
    hzDataPoint.setSize(1);
    hzDataPoint.setAddressOffset(16);
    hzDataPoint.setBlockOffset(14);
    hzDataPoint.setScaleFactorName("Hz_SF");
    hzDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(hzDataPoint.name(), hzDataPoint);

    SunSpecDataPoint hz_SFDataPoint;
    hz_SFDataPoint.setName("Hz_SF");
    hz_SFDataPoint.setDescription("Frequency scale factor");
    hz_SFDataPoint.setSize(1);
    hz_SFDataPoint.setAddressOffset(17);
    hz_SFDataPoint.setBlockOffset(15);
    hz_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(hz_SFDataPoint.name(), hz_SFDataPoint);

    SunSpecDataPoint wattsDataPoint;
    wattsDataPoint.setName("W");
    wattsDataPoint.setLabel("Watts");
    wattsDataPoint.setDescription("Total Real Power");
    wattsDataPoint.setUnits("W");
    wattsDataPoint.setMandatory(true);
    wattsDataPoint.setSize(1);
    wattsDataPoint.setAddressOffset(18);
    wattsDataPoint.setBlockOffset(16);
    wattsDataPoint.setScaleFactorName("W_SF");
    wattsDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(wattsDataPoint.name(), wattsDataPoint);

    SunSpecDataPoint wattsPhaseADataPoint;
    wattsPhaseADataPoint.setName("WphA");
    wattsPhaseADataPoint.setLabel("Watts phase A");
    wattsPhaseADataPoint.setUnits("W");
    wattsPhaseADataPoint.setSize(1);
    wattsPhaseADataPoint.setAddressOffset(19);
    wattsPhaseADataPoint.setBlockOffset(17);
    wattsPhaseADataPoint.setScaleFactorName("W_SF");
    wattsPhaseADataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(wattsPhaseADataPoint.name(), wattsPhaseADataPoint);

    SunSpecDataPoint wattsPhaseBDataPoint;
    wattsPhaseBDataPoint.setName("WphB");
    wattsPhaseBDataPoint.setLabel("Watts phase B");
    wattsPhaseBDataPoint.setUnits("W");
    wattsPhaseBDataPoint.setSize(1);
    wattsPhaseBDataPoint.setAddressOffset(20);
    wattsPhaseBDataPoint.setBlockOffset(18);
    wattsPhaseBDataPoint.setScaleFactorName("W_SF");
    wattsPhaseBDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(wattsPhaseBDataPoint.name(), wattsPhaseBDataPoint);

    SunSpecDataPoint wattsPhaseCDataPoint;
    wattsPhaseCDataPoint.setName("WphC");
    wattsPhaseCDataPoint.setLabel("Watts phase C");
    wattsPhaseCDataPoint.setUnits("W");
    wattsPhaseCDataPoint.setSize(1);
    wattsPhaseCDataPoint.setAddressOffset(21);
    wattsPhaseCDataPoint.setBlockOffset(19);
    wattsPhaseCDataPoint.setScaleFactorName("W_SF");
    wattsPhaseCDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(wattsPhaseCDataPoint.name(), wattsPhaseCDataPoint);

    SunSpecDataPoint w_SFDataPoint;
    w_SFDataPoint.setName("W_SF");
    w_SFDataPoint.setDescription("Real Power scale factor");
    w_SFDataPoint.setMandatory(true);
    w_SFDataPoint.setSize(1);
    w_SFDataPoint.setAddressOffset(22);
    w_SFDataPoint.setBlockOffset(20);
    w_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(w_SFDataPoint.name(), w_SFDataPoint);

    SunSpecDataPoint vaDataPoint;
    vaDataPoint.setName("VA");
    vaDataPoint.setLabel("VA");
    vaDataPoint.setDescription("AC Apparent Power");
    vaDataPoint.setUnits("VA");
    vaDataPoint.setSize(1);
    vaDataPoint.setAddressOffset(23);
    vaDataPoint.setBlockOffset(21);
    vaDataPoint.setScaleFactorName("VA_SF");
    vaDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vaDataPoint.name(), vaDataPoint);

    SunSpecDataPoint vaPhaseADataPoint;
    vaPhaseADataPoint.setName("VAphA");
    vaPhaseADataPoint.setLabel("VA phase A");
    vaPhaseADataPoint.setUnits("VA");
    vaPhaseADataPoint.setSize(1);
    vaPhaseADataPoint.setAddressOffset(24);
    vaPhaseADataPoint.setBlockOffset(22);
    vaPhaseADataPoint.setScaleFactorName("VA_SF");
    vaPhaseADataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vaPhaseADataPoint.name(), vaPhaseADataPoint);

    SunSpecDataPoint vaPhaseBDataPoint;
    vaPhaseBDataPoint.setName("VAphB");
    vaPhaseBDataPoint.setLabel("VA phase B");
    vaPhaseBDataPoint.setUnits("VA");
    vaPhaseBDataPoint.setSize(1);
    vaPhaseBDataPoint.setAddressOffset(25);
    vaPhaseBDataPoint.setBlockOffset(23);
    vaPhaseBDataPoint.setScaleFactorName("VA_SF");
    vaPhaseBDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vaPhaseBDataPoint.name(), vaPhaseBDataPoint);

    SunSpecDataPoint vaPhaseCDataPoint;
    vaPhaseCDataPoint.setName("VAphC");
    vaPhaseCDataPoint.setLabel("VA phase C");
    vaPhaseCDataPoint.setUnits("VA");
    vaPhaseCDataPoint.setSize(1);
    vaPhaseCDataPoint.setAddressOffset(26);
    vaPhaseCDataPoint.setBlockOffset(24);
    vaPhaseCDataPoint.setScaleFactorName("VA_SF");
    vaPhaseCDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(vaPhaseCDataPoint.name(), vaPhaseCDataPoint);

    SunSpecDataPoint vA_SFDataPoint;
    vA_SFDataPoint.setName("VA_SF");
    vA_SFDataPoint.setDescription("Apparent Power scale factor");
    vA_SFDataPoint.setSize(1);
    vA_SFDataPoint.setAddressOffset(27);
    vA_SFDataPoint.setBlockOffset(25);
    vA_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(vA_SFDataPoint.name(), vA_SFDataPoint);

    SunSpecDataPoint varDataPoint;
    varDataPoint.setName("VAR");
    varDataPoint.setLabel("VAR");
    varDataPoint.setDescription("Reactive Power");
    varDataPoint.setUnits("var");
    varDataPoint.setSize(1);
    varDataPoint.setAddressOffset(28);
    varDataPoint.setBlockOffset(26);
    varDataPoint.setScaleFactorName("VAR_SF");
    varDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(varDataPoint.name(), varDataPoint);

    SunSpecDataPoint varPhaseADataPoint;
    varPhaseADataPoint.setName("VARphA");
    varPhaseADataPoint.setLabel("VAR phase A");
    varPhaseADataPoint.setUnits("var");
    varPhaseADataPoint.setSize(1);
    varPhaseADataPoint.setAddressOffset(29);
    varPhaseADataPoint.setBlockOffset(27);
    varPhaseADataPoint.setScaleFactorName("VAR_SF");
    varPhaseADataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(varPhaseADataPoint.name(), varPhaseADataPoint);

    SunSpecDataPoint varPhaseBDataPoint;
    varPhaseBDataPoint.setName("VARphB");
    varPhaseBDataPoint.setLabel("VAR phase B");
    varPhaseBDataPoint.setUnits("var");
    varPhaseBDataPoint.setSize(1);
    varPhaseBDataPoint.setAddressOffset(30);
    varPhaseBDataPoint.setBlockOffset(28);
    varPhaseBDataPoint.setScaleFactorName("VAR_SF");
    varPhaseBDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(varPhaseBDataPoint.name(), varPhaseBDataPoint);

    SunSpecDataPoint varPhaseCDataPoint;
    varPhaseCDataPoint.setName("VARphC");
    varPhaseCDataPoint.setLabel("VAR phase C");
    varPhaseCDataPoint.setUnits("var");
    varPhaseCDataPoint.setSize(1);
    varPhaseCDataPoint.setAddressOffset(31);
    varPhaseCDataPoint.setBlockOffset(29);
    varPhaseCDataPoint.setScaleFactorName("VAR_SF");
    varPhaseCDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(varPhaseCDataPoint.name(), varPhaseCDataPoint);

    SunSpecDataPoint vAR_SFDataPoint;
    vAR_SFDataPoint.setName("VAR_SF");
    vAR_SFDataPoint.setDescription("Reactive Power scale factor");
    vAR_SFDataPoint.setSize(1);
    vAR_SFDataPoint.setAddressOffset(32);
    vAR_SFDataPoint.setBlockOffset(30);
    vAR_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(vAR_SFDataPoint.name(), vAR_SFDataPoint);

    SunSpecDataPoint pfDataPoint;
    pfDataPoint.setName("PF");
    pfDataPoint.setLabel("PF");
    pfDataPoint.setDescription("Power Factor");
    pfDataPoint.setUnits("Pct");
    pfDataPoint.setSize(1);
    pfDataPoint.setAddressOffset(33);
    pfDataPoint.setBlockOffset(31);
    pfDataPoint.setScaleFactorName("PF_SF");
    pfDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(pfDataPoint.name(), pfDataPoint);

    SunSpecDataPoint pfPhaseADataPoint;
    pfPhaseADataPoint.setName("PFphA");
    pfPhaseADataPoint.setLabel("PF phase A");
    pfPhaseADataPoint.setUnits("Pct");
    pfPhaseADataPoint.setSize(1);
    pfPhaseADataPoint.setAddressOffset(34);
    pfPhaseADataPoint.setBlockOffset(32);
    pfPhaseADataPoint.setScaleFactorName("PF_SF");
    pfPhaseADataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(pfPhaseADataPoint.name(), pfPhaseADataPoint);

    SunSpecDataPoint pfPhaseBDataPoint;
    pfPhaseBDataPoint.setName("PFphB");
    pfPhaseBDataPoint.setLabel("PF phase B");
    pfPhaseBDataPoint.setUnits("Pct");
    pfPhaseBDataPoint.setSize(1);
    pfPhaseBDataPoint.setAddressOffset(35);
    pfPhaseBDataPoint.setBlockOffset(33);
    pfPhaseBDataPoint.setScaleFactorName("PF_SF");
    pfPhaseBDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(pfPhaseBDataPoint.name(), pfPhaseBDataPoint);

    SunSpecDataPoint pfPhaseCDataPoint;
    pfPhaseCDataPoint.setName("PFphC");
    pfPhaseCDataPoint.setLabel("PF phase C");
    pfPhaseCDataPoint.setUnits("Pct");
    pfPhaseCDataPoint.setSize(1);
    pfPhaseCDataPoint.setAddressOffset(36);
    pfPhaseCDataPoint.setBlockOffset(34);
    pfPhaseCDataPoint.setScaleFactorName("PF_SF");
    pfPhaseCDataPoint.setSunSpecDataType("int16");
    m_dataPoints.insert(pfPhaseCDataPoint.name(), pfPhaseCDataPoint);

    SunSpecDataPoint pF_SFDataPoint;
    pF_SFDataPoint.setName("PF_SF");
    pF_SFDataPoint.setDescription("Power Factor scale factor");
    pF_SFDataPoint.setSize(1);
    pF_SFDataPoint.setAddressOffset(37);
    pF_SFDataPoint.setBlockOffset(35);
    pF_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(pF_SFDataPoint.name(), pF_SFDataPoint);

    SunSpecDataPoint totalWattHoursExportedDataPoint;
    totalWattHoursExportedDataPoint.setName("TotWhExp");
    totalWattHoursExportedDataPoint.setLabel("Total Watt-hours Exported");
    totalWattHoursExportedDataPoint.setDescription("Total Real Energy Exported");
    totalWattHoursExportedDataPoint.setUnits("Wh");
    totalWattHoursExportedDataPoint.setMandatory(true);
    totalWattHoursExportedDataPoint.setSize(2);
    totalWattHoursExportedDataPoint.setAddressOffset(38);
    totalWattHoursExportedDataPoint.setBlockOffset(36);
    totalWattHoursExportedDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursExportedDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursExportedDataPoint.name(), totalWattHoursExportedDataPoint);

    SunSpecDataPoint totalWattHoursExportedPhaseADataPoint;
    totalWattHoursExportedPhaseADataPoint.setName("TotWhExpPhA");
    totalWattHoursExportedPhaseADataPoint.setLabel("Total Watt-hours Exported phase A");
    totalWattHoursExportedPhaseADataPoint.setUnits("Wh");
    totalWattHoursExportedPhaseADataPoint.setSize(2);
    totalWattHoursExportedPhaseADataPoint.setAddressOffset(40);
    totalWattHoursExportedPhaseADataPoint.setBlockOffset(38);
    totalWattHoursExportedPhaseADataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursExportedPhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursExportedPhaseADataPoint.name(), totalWattHoursExportedPhaseADataPoint);

    SunSpecDataPoint totalWattHoursExportedPhaseBDataPoint;
    totalWattHoursExportedPhaseBDataPoint.setName("TotWhExpPhB");
    totalWattHoursExportedPhaseBDataPoint.setLabel("Total Watt-hours Exported phase B");
    totalWattHoursExportedPhaseBDataPoint.setUnits("Wh");
    totalWattHoursExportedPhaseBDataPoint.setSize(2);
    totalWattHoursExportedPhaseBDataPoint.setAddressOffset(42);
    totalWattHoursExportedPhaseBDataPoint.setBlockOffset(40);
    totalWattHoursExportedPhaseBDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursExportedPhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursExportedPhaseBDataPoint.name(), totalWattHoursExportedPhaseBDataPoint);

    SunSpecDataPoint totalWattHoursExportedPhaseCDataPoint;
    totalWattHoursExportedPhaseCDataPoint.setName("TotWhExpPhC");
    totalWattHoursExportedPhaseCDataPoint.setLabel("Total Watt-hours Exported phase C");
    totalWattHoursExportedPhaseCDataPoint.setUnits("Wh");
    totalWattHoursExportedPhaseCDataPoint.setSize(2);
    totalWattHoursExportedPhaseCDataPoint.setAddressOffset(44);
    totalWattHoursExportedPhaseCDataPoint.setBlockOffset(42);
    totalWattHoursExportedPhaseCDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursExportedPhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursExportedPhaseCDataPoint.name(), totalWattHoursExportedPhaseCDataPoint);

    SunSpecDataPoint totalWattHoursImportedDataPoint;
    totalWattHoursImportedDataPoint.setName("TotWhImp");
    totalWattHoursImportedDataPoint.setLabel("Total Watt-hours Imported");
    totalWattHoursImportedDataPoint.setDescription("Total Real Energy Imported");
    totalWattHoursImportedDataPoint.setUnits("Wh");
    totalWattHoursImportedDataPoint.setMandatory(true);
    totalWattHoursImportedDataPoint.setSize(2);
    totalWattHoursImportedDataPoint.setAddressOffset(46);
    totalWattHoursImportedDataPoint.setBlockOffset(44);
    totalWattHoursImportedDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursImportedDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursImportedDataPoint.name(), totalWattHoursImportedDataPoint);

    SunSpecDataPoint totalWattHoursImportedPhaseADataPoint;
    totalWattHoursImportedPhaseADataPoint.setName("TotWhImpPhA");
    totalWattHoursImportedPhaseADataPoint.setLabel("Total Watt-hours Imported phase A");
    totalWattHoursImportedPhaseADataPoint.setUnits("Wh");
    totalWattHoursImportedPhaseADataPoint.setSize(2);
    totalWattHoursImportedPhaseADataPoint.setAddressOffset(48);
    totalWattHoursImportedPhaseADataPoint.setBlockOffset(46);
    totalWattHoursImportedPhaseADataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursImportedPhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursImportedPhaseADataPoint.name(), totalWattHoursImportedPhaseADataPoint);

    SunSpecDataPoint totalWattHoursImportedPhaseBDataPoint;
    totalWattHoursImportedPhaseBDataPoint.setName("TotWhImpPhB");
    totalWattHoursImportedPhaseBDataPoint.setLabel("Total Watt-hours Imported phase B");
    totalWattHoursImportedPhaseBDataPoint.setUnits("Wh");
    totalWattHoursImportedPhaseBDataPoint.setSize(2);
    totalWattHoursImportedPhaseBDataPoint.setAddressOffset(50);
    totalWattHoursImportedPhaseBDataPoint.setBlockOffset(48);
    totalWattHoursImportedPhaseBDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursImportedPhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursImportedPhaseBDataPoint.name(), totalWattHoursImportedPhaseBDataPoint);

    SunSpecDataPoint totalWattHoursImportedPhaseCDataPoint;
    totalWattHoursImportedPhaseCDataPoint.setName("TotWhImpPhC");
    totalWattHoursImportedPhaseCDataPoint.setLabel("Total Watt-hours Imported phase C");
    totalWattHoursImportedPhaseCDataPoint.setUnits("Wh");
    totalWattHoursImportedPhaseCDataPoint.setSize(2);
    totalWattHoursImportedPhaseCDataPoint.setAddressOffset(52);
    totalWattHoursImportedPhaseCDataPoint.setBlockOffset(50);
    totalWattHoursImportedPhaseCDataPoint.setScaleFactorName("TotWh_SF");
    totalWattHoursImportedPhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalWattHoursImportedPhaseCDataPoint.name(), totalWattHoursImportedPhaseCDataPoint);

    SunSpecDataPoint totWh_SFDataPoint;
    totWh_SFDataPoint.setName("TotWh_SF");
    totWh_SFDataPoint.setDescription("Real Energy scale factor");
    totWh_SFDataPoint.setMandatory(true);
    totWh_SFDataPoint.setSize(1);
    totWh_SFDataPoint.setAddressOffset(54);
    totWh_SFDataPoint.setBlockOffset(52);
    totWh_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(totWh_SFDataPoint.name(), totWh_SFDataPoint);

    SunSpecDataPoint totalVaHoursExportedDataPoint;
    totalVaHoursExportedDataPoint.setName("TotVAhExp");
    totalVaHoursExportedDataPoint.setLabel("Total VA-hours Exported");
    totalVaHoursExportedDataPoint.setDescription("Total Apparent Energy Exported");
    totalVaHoursExportedDataPoint.setUnits("VAh");
    totalVaHoursExportedDataPoint.setSize(2);
    totalVaHoursExportedDataPoint.setAddressOffset(55);
    totalVaHoursExportedDataPoint.setBlockOffset(53);
    totalVaHoursExportedDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursExportedDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursExportedDataPoint.name(), totalVaHoursExportedDataPoint);

    SunSpecDataPoint totalVaHoursExportedPhaseADataPoint;
    totalVaHoursExportedPhaseADataPoint.setName("TotVAhExpPhA");
    totalVaHoursExportedPhaseADataPoint.setLabel("Total VA-hours Exported phase A");
    totalVaHoursExportedPhaseADataPoint.setUnits("VAh");
    totalVaHoursExportedPhaseADataPoint.setSize(2);
    totalVaHoursExportedPhaseADataPoint.setAddressOffset(57);
    totalVaHoursExportedPhaseADataPoint.setBlockOffset(55);
    totalVaHoursExportedPhaseADataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursExportedPhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursExportedPhaseADataPoint.name(), totalVaHoursExportedPhaseADataPoint);

    SunSpecDataPoint totalVaHoursExportedPhaseBDataPoint;
    totalVaHoursExportedPhaseBDataPoint.setName("TotVAhExpPhB");
    totalVaHoursExportedPhaseBDataPoint.setLabel("Total VA-hours Exported phase B");
    totalVaHoursExportedPhaseBDataPoint.setUnits("VAh");
    totalVaHoursExportedPhaseBDataPoint.setSize(2);
    totalVaHoursExportedPhaseBDataPoint.setAddressOffset(59);
    totalVaHoursExportedPhaseBDataPoint.setBlockOffset(57);
    totalVaHoursExportedPhaseBDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursExportedPhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursExportedPhaseBDataPoint.name(), totalVaHoursExportedPhaseBDataPoint);

    SunSpecDataPoint totalVaHoursExportedPhaseCDataPoint;
    totalVaHoursExportedPhaseCDataPoint.setName("TotVAhExpPhC");
    totalVaHoursExportedPhaseCDataPoint.setLabel("Total VA-hours Exported phase C");
    totalVaHoursExportedPhaseCDataPoint.setUnits("VAh");
    totalVaHoursExportedPhaseCDataPoint.setSize(2);
    totalVaHoursExportedPhaseCDataPoint.setAddressOffset(61);
    totalVaHoursExportedPhaseCDataPoint.setBlockOffset(59);
    totalVaHoursExportedPhaseCDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursExportedPhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursExportedPhaseCDataPoint.name(), totalVaHoursExportedPhaseCDataPoint);

    SunSpecDataPoint totalVaHoursImportedDataPoint;
    totalVaHoursImportedDataPoint.setName("TotVAhImp");
    totalVaHoursImportedDataPoint.setLabel("Total VA-hours Imported");
    totalVaHoursImportedDataPoint.setDescription("Total Apparent Energy Imported");
    totalVaHoursImportedDataPoint.setUnits("VAh");
    totalVaHoursImportedDataPoint.setSize(2);
    totalVaHoursImportedDataPoint.setAddressOffset(63);
    totalVaHoursImportedDataPoint.setBlockOffset(61);
    totalVaHoursImportedDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursImportedDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursImportedDataPoint.name(), totalVaHoursImportedDataPoint);

    SunSpecDataPoint totalVaHoursImportedPhaseADataPoint;
    totalVaHoursImportedPhaseADataPoint.setName("TotVAhImpPhA");
    totalVaHoursImportedPhaseADataPoint.setLabel("Total VA-hours Imported phase A");
    totalVaHoursImportedPhaseADataPoint.setUnits("VAh");
    totalVaHoursImportedPhaseADataPoint.setSize(2);
    totalVaHoursImportedPhaseADataPoint.setAddressOffset(65);
    totalVaHoursImportedPhaseADataPoint.setBlockOffset(63);
    totalVaHoursImportedPhaseADataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursImportedPhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursImportedPhaseADataPoint.name(), totalVaHoursImportedPhaseADataPoint);

    SunSpecDataPoint totalVaHoursImportedPhaseBDataPoint;
    totalVaHoursImportedPhaseBDataPoint.setName("TotVAhImpPhB");
    totalVaHoursImportedPhaseBDataPoint.setLabel("Total VA-hours Imported phase B");
    totalVaHoursImportedPhaseBDataPoint.setUnits("VAh");
    totalVaHoursImportedPhaseBDataPoint.setSize(2);
    totalVaHoursImportedPhaseBDataPoint.setAddressOffset(67);
    totalVaHoursImportedPhaseBDataPoint.setBlockOffset(65);
    totalVaHoursImportedPhaseBDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursImportedPhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursImportedPhaseBDataPoint.name(), totalVaHoursImportedPhaseBDataPoint);

    SunSpecDataPoint totalVaHoursImportedPhaseCDataPoint;
    totalVaHoursImportedPhaseCDataPoint.setName("TotVAhImpPhC");
    totalVaHoursImportedPhaseCDataPoint.setLabel("Total VA-hours Imported phase C");
    totalVaHoursImportedPhaseCDataPoint.setUnits("VAh");
    totalVaHoursImportedPhaseCDataPoint.setSize(2);
    totalVaHoursImportedPhaseCDataPoint.setAddressOffset(69);
    totalVaHoursImportedPhaseCDataPoint.setBlockOffset(67);
    totalVaHoursImportedPhaseCDataPoint.setScaleFactorName("TotVAh_SF");
    totalVaHoursImportedPhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVaHoursImportedPhaseCDataPoint.name(), totalVaHoursImportedPhaseCDataPoint);

    SunSpecDataPoint totVAh_SFDataPoint;
    totVAh_SFDataPoint.setName("TotVAh_SF");
    totVAh_SFDataPoint.setDescription("Apparent Energy scale factor");
    totVAh_SFDataPoint.setSize(1);
    totVAh_SFDataPoint.setAddressOffset(71);
    totVAh_SFDataPoint.setBlockOffset(69);
    totVAh_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(totVAh_SFDataPoint.name(), totVAh_SFDataPoint);

    SunSpecDataPoint totalVarHoursImportedQ1DataPoint;
    totalVarHoursImportedQ1DataPoint.setName("TotVArhImpQ1");
    totalVarHoursImportedQ1DataPoint.setLabel("Total VAR-hours Imported Q1");
    totalVarHoursImportedQ1DataPoint.setDescription("Total Reactive Energy Imported Quadrant 1");
    totalVarHoursImportedQ1DataPoint.setUnits("varh");
    totalVarHoursImportedQ1DataPoint.setSize(2);
    totalVarHoursImportedQ1DataPoint.setAddressOffset(72);
    totalVarHoursImportedQ1DataPoint.setBlockOffset(70);
    totalVarHoursImportedQ1DataPoint.setScaleFactorName("TotVArh_SF");
    totalVarHoursImportedQ1DataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVarHoursImportedQ1DataPoint.name(), totalVarHoursImportedQ1DataPoint);

    SunSpecDataPoint totalVArHoursImportedQ1PhaseADataPoint;
    totalVArHoursImportedQ1PhaseADataPoint.setName("TotVArhImpQ1PhA");
    totalVArHoursImportedQ1PhaseADataPoint.setLabel("Total VAr-hours Imported Q1 phase A");
    totalVArHoursImportedQ1PhaseADataPoint.setUnits("varh");
    totalVArHoursImportedQ1PhaseADataPoint.setSize(2);
    totalVArHoursImportedQ1PhaseADataPoint.setAddressOffset(74);
    totalVArHoursImportedQ1PhaseADataPoint.setBlockOffset(72);
    totalVArHoursImportedQ1PhaseADataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ1PhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ1PhaseADataPoint.name(), totalVArHoursImportedQ1PhaseADataPoint);

    SunSpecDataPoint totalVArHoursImportedQ1PhaseBDataPoint;
    totalVArHoursImportedQ1PhaseBDataPoint.setName("TotVArhImpQ1PhB");
    totalVArHoursImportedQ1PhaseBDataPoint.setLabel("Total VAr-hours Imported Q1 phase B");
    totalVArHoursImportedQ1PhaseBDataPoint.setUnits("varh");
    totalVArHoursImportedQ1PhaseBDataPoint.setSize(2);
    totalVArHoursImportedQ1PhaseBDataPoint.setAddressOffset(76);
    totalVArHoursImportedQ1PhaseBDataPoint.setBlockOffset(74);
    totalVArHoursImportedQ1PhaseBDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ1PhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ1PhaseBDataPoint.name(), totalVArHoursImportedQ1PhaseBDataPoint);

    SunSpecDataPoint totalVArHoursImportedQ1PhaseCDataPoint;
    totalVArHoursImportedQ1PhaseCDataPoint.setName("TotVArhImpQ1PhC");
    totalVArHoursImportedQ1PhaseCDataPoint.setLabel("Total VAr-hours Imported Q1 phase C");
    totalVArHoursImportedQ1PhaseCDataPoint.setUnits("varh");
    totalVArHoursImportedQ1PhaseCDataPoint.setSize(2);
    totalVArHoursImportedQ1PhaseCDataPoint.setAddressOffset(78);
    totalVArHoursImportedQ1PhaseCDataPoint.setBlockOffset(76);
    totalVArHoursImportedQ1PhaseCDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ1PhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ1PhaseCDataPoint.name(), totalVArHoursImportedQ1PhaseCDataPoint);

    SunSpecDataPoint totalVArHoursImportedQ2DataPoint;
    totalVArHoursImportedQ2DataPoint.setName("TotVArhImpQ2");
    totalVArHoursImportedQ2DataPoint.setLabel("Total VAr-hours Imported Q2");
    totalVArHoursImportedQ2DataPoint.setDescription("Total Reactive Power Imported Quadrant 2");
    totalVArHoursImportedQ2DataPoint.setUnits("varh");
    totalVArHoursImportedQ2DataPoint.setSize(2);
    totalVArHoursImportedQ2DataPoint.setAddressOffset(80);
    totalVArHoursImportedQ2DataPoint.setBlockOffset(78);
    totalVArHoursImportedQ2DataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ2DataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ2DataPoint.name(), totalVArHoursImportedQ2DataPoint);

    SunSpecDataPoint totalVArHoursImportedQ2PhaseADataPoint;
    totalVArHoursImportedQ2PhaseADataPoint.setName("TotVArhImpQ2PhA");
    totalVArHoursImportedQ2PhaseADataPoint.setLabel("Total VAr-hours Imported Q2 phase A");
    totalVArHoursImportedQ2PhaseADataPoint.setUnits("varh");
    totalVArHoursImportedQ2PhaseADataPoint.setSize(2);
    totalVArHoursImportedQ2PhaseADataPoint.setAddressOffset(82);
    totalVArHoursImportedQ2PhaseADataPoint.setBlockOffset(80);
    totalVArHoursImportedQ2PhaseADataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ2PhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ2PhaseADataPoint.name(), totalVArHoursImportedQ2PhaseADataPoint);

    SunSpecDataPoint totalVArHoursImportedQ2PhaseBDataPoint;
    totalVArHoursImportedQ2PhaseBDataPoint.setName("TotVArhImpQ2PhB");
    totalVArHoursImportedQ2PhaseBDataPoint.setLabel("Total VAr-hours Imported Q2 phase B");
    totalVArHoursImportedQ2PhaseBDataPoint.setUnits("varh");
    totalVArHoursImportedQ2PhaseBDataPoint.setSize(2);
    totalVArHoursImportedQ2PhaseBDataPoint.setAddressOffset(84);
    totalVArHoursImportedQ2PhaseBDataPoint.setBlockOffset(82);
    totalVArHoursImportedQ2PhaseBDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ2PhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ2PhaseBDataPoint.name(), totalVArHoursImportedQ2PhaseBDataPoint);

    SunSpecDataPoint totalVArHoursImportedQ2PhaseCDataPoint;
    totalVArHoursImportedQ2PhaseCDataPoint.setName("TotVArhImpQ2PhC");
    totalVArHoursImportedQ2PhaseCDataPoint.setLabel("Total VAr-hours Imported Q2 phase C");
    totalVArHoursImportedQ2PhaseCDataPoint.setUnits("varh");
    totalVArHoursImportedQ2PhaseCDataPoint.setSize(2);
    totalVArHoursImportedQ2PhaseCDataPoint.setAddressOffset(86);
    totalVArHoursImportedQ2PhaseCDataPoint.setBlockOffset(84);
    totalVArHoursImportedQ2PhaseCDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursImportedQ2PhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursImportedQ2PhaseCDataPoint.name(), totalVArHoursImportedQ2PhaseCDataPoint);

    SunSpecDataPoint totalVArHoursExportedQ3DataPoint;
    totalVArHoursExportedQ3DataPoint.setName("TotVArhExpQ3");
    totalVArHoursExportedQ3DataPoint.setLabel("Total VAr-hours Exported Q3");
    totalVArHoursExportedQ3DataPoint.setDescription("Total Reactive Power Exported Quadrant 3");
    totalVArHoursExportedQ3DataPoint.setUnits("varh");
    totalVArHoursExportedQ3DataPoint.setSize(2);
    totalVArHoursExportedQ3DataPoint.setAddressOffset(88);
    totalVArHoursExportedQ3DataPoint.setBlockOffset(86);
    totalVArHoursExportedQ3DataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ3DataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ3DataPoint.name(), totalVArHoursExportedQ3DataPoint);

    SunSpecDataPoint totalVArHoursExportedQ3PhaseADataPoint;
    totalVArHoursExportedQ3PhaseADataPoint.setName("TotVArhExpQ3PhA");
    totalVArHoursExportedQ3PhaseADataPoint.setLabel("Total VAr-hours Exported Q3 phase A");
    totalVArHoursExportedQ3PhaseADataPoint.setUnits("varh");
    totalVArHoursExportedQ3PhaseADataPoint.setSize(2);
    totalVArHoursExportedQ3PhaseADataPoint.setAddressOffset(90);
    totalVArHoursExportedQ3PhaseADataPoint.setBlockOffset(88);
    totalVArHoursExportedQ3PhaseADataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ3PhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ3PhaseADataPoint.name(), totalVArHoursExportedQ3PhaseADataPoint);

    SunSpecDataPoint totalVArHoursExportedQ3PhaseBDataPoint;
    totalVArHoursExportedQ3PhaseBDataPoint.setName("TotVArhExpQ3PhB");
    totalVArHoursExportedQ3PhaseBDataPoint.setLabel("Total VAr-hours Exported Q3 phase B");
    totalVArHoursExportedQ3PhaseBDataPoint.setUnits("varh");
    totalVArHoursExportedQ3PhaseBDataPoint.setSize(2);
    totalVArHoursExportedQ3PhaseBDataPoint.setAddressOffset(92);
    totalVArHoursExportedQ3PhaseBDataPoint.setBlockOffset(90);
    totalVArHoursExportedQ3PhaseBDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ3PhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ3PhaseBDataPoint.name(), totalVArHoursExportedQ3PhaseBDataPoint);

    SunSpecDataPoint totalVArHoursExportedQ3PhaseCDataPoint;
    totalVArHoursExportedQ3PhaseCDataPoint.setName("TotVArhExpQ3PhC");
    totalVArHoursExportedQ3PhaseCDataPoint.setLabel("Total VAr-hours Exported Q3 phase C");
    totalVArHoursExportedQ3PhaseCDataPoint.setUnits("varh");
    totalVArHoursExportedQ3PhaseCDataPoint.setSize(2);
    totalVArHoursExportedQ3PhaseCDataPoint.setAddressOffset(94);
    totalVArHoursExportedQ3PhaseCDataPoint.setBlockOffset(92);
    totalVArHoursExportedQ3PhaseCDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ3PhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ3PhaseCDataPoint.name(), totalVArHoursExportedQ3PhaseCDataPoint);

    SunSpecDataPoint totalVArHoursExportedQ4DataPoint;
    totalVArHoursExportedQ4DataPoint.setName("TotVArhExpQ4");
    totalVArHoursExportedQ4DataPoint.setLabel("Total VAr-hours Exported Q4");
    totalVArHoursExportedQ4DataPoint.setDescription("Total Reactive Power Exported Quadrant 4");
    totalVArHoursExportedQ4DataPoint.setUnits("varh");
    totalVArHoursExportedQ4DataPoint.setSize(2);
    totalVArHoursExportedQ4DataPoint.setAddressOffset(96);
    totalVArHoursExportedQ4DataPoint.setBlockOffset(94);
    totalVArHoursExportedQ4DataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ4DataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ4DataPoint.name(), totalVArHoursExportedQ4DataPoint);

    SunSpecDataPoint totalVArHoursExportedQ4ImportedPhaseADataPoint;
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setName("TotVArhExpQ4PhA");
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setLabel("Total VAr-hours Exported Q4 Imported phase A");
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setUnits("varh");
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setSize(2);
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setAddressOffset(98);
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setBlockOffset(96);
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ4ImportedPhaseADataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ4ImportedPhaseADataPoint.name(), totalVArHoursExportedQ4ImportedPhaseADataPoint);

    SunSpecDataPoint totalVArHoursExportedQ4ImportedPhaseBDataPoint;
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setName("TotVArhExpQ4PhB");
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setLabel("Total VAr-hours Exported Q4 Imported phase B");
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setUnits("varh");
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setSize(2);
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setAddressOffset(100);
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setBlockOffset(98);
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ4ImportedPhaseBDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ4ImportedPhaseBDataPoint.name(), totalVArHoursExportedQ4ImportedPhaseBDataPoint);

    SunSpecDataPoint totalVArHoursExportedQ4ImportedPhaseCDataPoint;
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setName("TotVArhExpQ4PhC");
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setLabel("Total VAr-hours Exported Q4 Imported phase C");
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setUnits("varh");
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setSize(2);
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setAddressOffset(102);
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setBlockOffset(100);
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setScaleFactorName("TotVArh_SF");
    totalVArHoursExportedQ4ImportedPhaseCDataPoint.setSunSpecDataType("acc32");
    m_dataPoints.insert(totalVArHoursExportedQ4ImportedPhaseCDataPoint.name(), totalVArHoursExportedQ4ImportedPhaseCDataPoint);

    SunSpecDataPoint totVArh_SFDataPoint;
    totVArh_SFDataPoint.setName("TotVArh_SF");
    totVArh_SFDataPoint.setDescription("Reactive Energy scale factor");
    totVArh_SFDataPoint.setSize(1);
    totVArh_SFDataPoint.setAddressOffset(104);
    totVArh_SFDataPoint.setBlockOffset(102);
    totVArh_SFDataPoint.setSunSpecDataType("sunssf");
    m_dataPoints.insert(totVArh_SFDataPoint.name(), totVArh_SFDataPoint);

    SunSpecDataPoint eventsDataPoint;
    eventsDataPoint.setName("Evt");
    eventsDataPoint.setLabel("Events");
    eventsDataPoint.setDescription("Meter Event Flags");
    eventsDataPoint.setMandatory(true);
    eventsDataPoint.setSize(2);
    eventsDataPoint.setAddressOffset(105);
    eventsDataPoint.setBlockOffset(103);
    eventsDataPoint.setSunSpecDataType("bitfield32");
    m_dataPoints.insert(eventsDataPoint.name(), eventsDataPoint);

}

QDebug operator<<(QDebug debug, SunSpecMeterSinglePhaseModel *model)
{
    debug.nospace().noquote() << "SunSpecMeterSinglePhaseModel(Model: " << model->modelId() << ", Register: " << model->modbusStartRegister() << ", Length: " << model->modelLength() << ")" << endl;
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

    if (model->dataPoints().value("PhV").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhV") << "--> " << model->voltageLn() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PhV") << "--> NaN" << endl;
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

    if (model->dataPoints().value("PPV").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPV") << "--> " << model->voltageLl() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PPV") << "--> NaN" << endl;
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

    if (model->dataPoints().value("Hz").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Hz") << "--> " << model->hz() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Hz") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("W").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("W") << "--> " << model->watts() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("W") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("WphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphA") << "--> " << model->wattsPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("WphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphB") << "--> " << model->wattsPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("WphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphC") << "--> " << model->wattsPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("WphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VA") << "--> " << model->va() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VAphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphA") << "--> " << model->vaPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VAphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphB") << "--> " << model->vaPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VAphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphC") << "--> " << model->vaPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VAR").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAR") << "--> " << model->var() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VAR") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VARphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphA") << "--> " << model->varPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VARphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphB") << "--> " << model->varPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("VARphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphC") << "--> " << model->varPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("VARphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PF").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PF") << "--> " << model->pf() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PF") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PFphA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphA") << "--> " << model->pfPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PFphB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphB") << "--> " << model->pfPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("PFphC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphC") << "--> " << model->pfPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("PFphC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhExp").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExp") << "--> " << model->totalWattHoursExported() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExp") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhExpPhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhA") << "--> " << model->totalWattHoursExportedPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhExpPhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhB") << "--> " << model->totalWattHoursExportedPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhExpPhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhC") << "--> " << model->totalWattHoursExportedPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhExpPhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhImp").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImp") << "--> " << model->totalWattHoursImported() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImp") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhImpPhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhA") << "--> " << model->totalWattHoursImportedPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhImpPhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhB") << "--> " << model->totalWattHoursImportedPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotWhImpPhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhC") << "--> " << model->totalWattHoursImportedPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotWhImpPhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhExp").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExp") << "--> " << model->totalVaHoursExported() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExp") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhExpPhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhA") << "--> " << model->totalVaHoursExportedPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhExpPhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhB") << "--> " << model->totalVaHoursExportedPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhExpPhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhC") << "--> " << model->totalVaHoursExportedPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhExpPhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhImp").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImp") << "--> " << model->totalVaHoursImported() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImp") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhImpPhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhA") << "--> " << model->totalVaHoursImportedPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhImpPhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhB") << "--> " << model->totalVaHoursImportedPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVAhImpPhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhC") << "--> " << model->totalVaHoursImportedPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVAhImpPhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ1").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1") << "--> " << model->totalVarHoursImportedQ1() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ1PhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhA") << "--> " << model->totalVArHoursImportedQ1PhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ1PhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhB") << "--> " << model->totalVArHoursImportedQ1PhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ1PhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhC") << "--> " << model->totalVArHoursImportedQ1PhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ1PhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ2").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2") << "--> " << model->totalVArHoursImportedQ2() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ2PhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhA") << "--> " << model->totalVArHoursImportedQ2PhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ2PhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhB") << "--> " << model->totalVArHoursImportedQ2PhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhImpQ2PhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhC") << "--> " << model->totalVArHoursImportedQ2PhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhImpQ2PhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ3").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3") << "--> " << model->totalVArHoursExportedQ3() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ3PhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhA") << "--> " << model->totalVArHoursExportedQ3PhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ3PhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhB") << "--> " << model->totalVArHoursExportedQ3PhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ3PhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhC") << "--> " << model->totalVArHoursExportedQ3PhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ3PhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ4").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4") << "--> " << model->totalVArHoursExportedQ4() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ4PhA").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhA") << "--> " << model->totalVArHoursExportedQ4ImportedPhaseA() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhA") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ4PhB").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhB") << "--> " << model->totalVArHoursExportedQ4ImportedPhaseB() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhB") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("TotVArhExpQ4PhC").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhC") << "--> " << model->totalVArHoursExportedQ4ImportedPhaseC() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("TotVArhExpQ4PhC") << "--> NaN" << endl;
    }

    if (model->dataPoints().value("Evt").isValid()) {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt") << "--> " << model->events() << endl;
    } else {
        debug.nospace().noquote() << "    - " << model->dataPoints().value("Evt") << "--> NaN" << endl;
    }


    return debug.space().quote();
}
