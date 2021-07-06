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

#ifndef SUNSPECBASEMETMODEL_H
#define SUNSPECBASEMETMODEL_H

#include <QObject>

#include "sunspecmodel.h"

class SunSpecConnection;

class SunSpecBaseMetModel : public SunSpecModel
{
    Q_OBJECT
public:

    explicit SunSpecBaseMetModel(SunSpecConnection *connection, quint16 modbusStartRegister, quint16 length, QObject *parent = nullptr);
    ~SunSpecBaseMetModel() override; 

    QString name() const override;
    QString description() const override;
    QString label() const override;

    float ambientTemperature() const;
    qint16 relativeHumidity() const;
    qint16 barometricPressure() const;
    qint16 windSpeed() const;
    qint16 windDirection() const;
    qint16 rainfall() const;
    qint16 snowDepth() const;
    qint16 precipitationType() const;
    qint16 electricField() const;
    qint16 surfaceWetness() const;
    qint16 soilWetness() const;

protected:
    void processBlockData() override;

private:
    float m_ambientTemperature = 0;
    qint16 m_relativeHumidity = 0;
    qint16 m_barometricPressure = 0;
    qint16 m_windSpeed = 0;
    qint16 m_windDirection = 0;
    qint16 m_rainfall = 0;
    qint16 m_snowDepth = 0;
    qint16 m_precipitationType = 0;
    qint16 m_electricField = 0;
    qint16 m_surfaceWetness = 0;
    qint16 m_soilWetness = 0;

    void initDataPoints();

};

QDebug operator<<(QDebug debug, SunSpecBaseMetModel *model);

#endif // SUNSPECBASEMETMODEL_H
