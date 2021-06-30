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

#include "sunspeclocationmodel.h"

SunSpecLocationModel::SunSpecLocationModel(SunSpec *connection, quint16 modelId, quint16 modelLength, quint16 modbusStartRegister, QObject *parent) :
    SunSpecModel(connection, modelId, modelLength, modbusStartRegister, parent)
{
    initDataPoints();
    m_supportedModelIds << 305;
}

SunSpecLocationModel::~SunSpecLocationModel()
{

}

QString SunSpecLocationModel::name() const
{
    return "location";
}

QString SunSpecLocationModel::description() const
{
    return "Include to support location measurements";
}

QString SunSpecLocationModel::label() const
{
    return "GPS";
}

void SunSpecLocationModel::readModelHeader()
{

}

void SunSpecLocationModel::readBlockData()
{

}

void SunSpecLocationModel::initDataPoints()
{
    SunSpecDataPoint modelIdDataPoint;
    modelIdDataPoint.setName("ID");
    modelIdDataPoint.setLabel("Model ID");
    modelIdDataPoint.setDescription("Model identifier");
    modelIdDataPoint.setMandatory(true);
    modelIdDataPoint.setSize(1);
    modelIdDataPoint.setAddressOffset(0);
    modelIdDataPoint.setDataType(SunSpecDataPoint::stringToDataType("uint16"));
    m_dataPoints.insert(modelIdDataPoint.name(), modelIdDataPoint);

    SunSpecDataPoint modelLengthDataPoint;
    modelLengthDataPoint.setName("L");
    modelLengthDataPoint.setLabel("Model Length");
    modelLengthDataPoint.setDescription("Model length");
    modelLengthDataPoint.setMandatory(true);
    modelLengthDataPoint.setSize(1);
    modelLengthDataPoint.setAddressOffset(1);
    modelLengthDataPoint.setDataType(SunSpecDataPoint::stringToDataType("uint16"));
    m_dataPoints.insert(modelLengthDataPoint.name(), modelLengthDataPoint);

    SunSpecDataPoint tmDataPoint;
    tmDataPoint.setName("Tm");
    tmDataPoint.setLabel("Tm");
    tmDataPoint.setDescription("UTC 24 hour time stamp to millisecond hhmmss.sssZ format");
    tmDataPoint.setUnits("hhmmss.sssZ");
    tmDataPoint.setSize(6);
    tmDataPoint.setAddressOffset(2);
    tmDataPoint.setBlockOffset(0);
    tmDataPoint.setDataType(SunSpecDataPoint::stringToDataType("string"));
    m_dataPoints.insert(tmDataPoint.name(), tmDataPoint);

    SunSpecDataPoint dateDataPoint;
    dateDataPoint.setName("Date");
    dateDataPoint.setLabel("Date");
    dateDataPoint.setDescription("UTC Date string YYYYMMDD format");
    dateDataPoint.setUnits("YYYYMMDD");
    dateDataPoint.setSize(4);
    dateDataPoint.setAddressOffset(8);
    dateDataPoint.setBlockOffset(6);
    dateDataPoint.setDataType(SunSpecDataPoint::stringToDataType("string"));
    m_dataPoints.insert(dateDataPoint.name(), dateDataPoint);

    SunSpecDataPoint locationDataPoint;
    locationDataPoint.setName("Loc");
    locationDataPoint.setLabel("Location");
    locationDataPoint.setDescription("Location string (40 chars max)");
    locationDataPoint.setUnits("text");
    locationDataPoint.setSize(20);
    locationDataPoint.setAddressOffset(12);
    locationDataPoint.setBlockOffset(10);
    locationDataPoint.setDataType(SunSpecDataPoint::stringToDataType("string"));
    m_dataPoints.insert(locationDataPoint.name(), locationDataPoint);

    SunSpecDataPoint latDataPoint;
    latDataPoint.setName("Lat");
    latDataPoint.setLabel("Lat");
    latDataPoint.setDescription("Latitude with seven degrees of precision");
    latDataPoint.setUnits("Degrees");
    latDataPoint.setSize(2);
    latDataPoint.setAddressOffset(32);
    latDataPoint.setBlockOffset(30);
    latDataPoint.setScaleFactorName("-7");
    latDataPoint.setDataType(SunSpecDataPoint::stringToDataType("int32"));
    m_dataPoints.insert(latDataPoint.name(), latDataPoint);

    SunSpecDataPoint longDataPoint;
    longDataPoint.setName("Long");
    longDataPoint.setLabel("Long");
    longDataPoint.setDescription("Longitude with seven degrees of precision");
    longDataPoint.setUnits("Degrees");
    longDataPoint.setSize(2);
    longDataPoint.setAddressOffset(34);
    longDataPoint.setBlockOffset(32);
    longDataPoint.setScaleFactorName("-7");
    longDataPoint.setDataType(SunSpecDataPoint::stringToDataType("int32"));
    m_dataPoints.insert(longDataPoint.name(), longDataPoint);

    SunSpecDataPoint altitudeDataPoint;
    altitudeDataPoint.setName("Alt");
    altitudeDataPoint.setLabel("Altitude");
    altitudeDataPoint.setDescription("Altitude measurement in meters");
    altitudeDataPoint.setUnits("meters");
    altitudeDataPoint.setSize(2);
    altitudeDataPoint.setAddressOffset(36);
    altitudeDataPoint.setBlockOffset(34);
    altitudeDataPoint.setDataType(SunSpecDataPoint::stringToDataType("int32"));
    m_dataPoints.insert(altitudeDataPoint.name(), altitudeDataPoint);

}
