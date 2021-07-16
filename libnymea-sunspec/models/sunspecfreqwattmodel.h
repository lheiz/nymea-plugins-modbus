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

#ifndef SUNSPECFREQWATTMODEL_H
#define SUNSPECFREQWATTMODEL_H

#include <QObject>

#include "sunspecmodel.h"
#include "sunspecmodelrepeatingblock.h"

class SunSpecConnection;
class SunSpecFreqWattModel;

class SunSpecFreqWattModelRepeatingBlock : public SunSpecModelRepeatingBlock
{
    Q_OBJECT
public:

    enum Readonly {
        ReadonlyReadwrite = 0,
        ReadonlyReadonly = 1
    };
    Q_ENUM(Readonly)

    explicit SunSpecFreqWattModelRepeatingBlock(quint16 blockIndex, quint16 blockSize, quint16 modbusStartRegister, SunSpecFreqWattModel *parent = nullptr);
    ~SunSpecFreqWattModelRepeatingBlock() override = default;

    SunSpecFreqWattModel *parentModel() const;

    QString name() const override;

    quint16 actPt() const;
    QModbusReply *setActPt(quint16 actPt);

    float hz1() const;
    QModbusReply *setHz1(float hz1);

    float w1() const;
    QModbusReply *setW1(float w1);

    float hz2() const;
    QModbusReply *setHz2(float hz2);

    float w2() const;
    QModbusReply *setW2(float w2);

    float hz3() const;
    QModbusReply *setHz3(float hz3);

    float w3() const;
    QModbusReply *setW3(float w3);

    float hz4() const;
    QModbusReply *setHz4(float hz4);

    float w4() const;
    QModbusReply *setW4(float w4);

    float hz5() const;
    QModbusReply *setHz5(float hz5);

    float w5() const;
    QModbusReply *setW5(float w5);

    float hz6() const;
    QModbusReply *setHz6(float hz6);

    float w6() const;
    QModbusReply *setW6(float w6);

    float hz7() const;
    QModbusReply *setHz7(float hz7);

    float w7() const;
    QModbusReply *setW7(float w7);

    float hz8() const;
    QModbusReply *setHz8(float hz8);

    float w8() const;
    QModbusReply *setW8(float w8);

    float hz9() const;
    QModbusReply *setHz9(float hz9);

    float w9() const;
    QModbusReply *setW9(float w9);

    float hz10() const;
    QModbusReply *setHz10(float hz10);

    float w10() const;
    QModbusReply *setW10(float w10);

    float hz11() const;
    QModbusReply *setHz11(float hz11);

    float w11() const;
    QModbusReply *setW11(float w11);

    float hz12() const;
    QModbusReply *setHz12(float hz12);

    float w12() const;
    QModbusReply *setW12(float w12);

    float hz13() const;
    QModbusReply *setHz13(float hz13);

    float w13() const;
    QModbusReply *setW13(float w13);

    float hz14() const;
    QModbusReply *setHz14(float hz14);

    float w14() const;
    QModbusReply *setW14(float w14);

    float hz15() const;
    QModbusReply *setHz15(float hz15);

    float w15() const;
    QModbusReply *setW15(float w15);

    float hz16() const;
    QModbusReply *setHz16(float hz16);

    float w16() const;
    QModbusReply *setW16(float w16);

    float hz17() const;
    QModbusReply *setHz17(float hz17);

    float w17() const;
    QModbusReply *setW17(float w17);

    float hz18() const;
    QModbusReply *setHz18(float hz18);

    float w18() const;
    QModbusReply *setW18(float w18);

    float hz19() const;
    QModbusReply *setHz19(float hz19);

    float w19() const;
    QModbusReply *setW19(float w19);

    float hz20() const;
    QModbusReply *setHz20(float hz20);

    float w20() const;
    QModbusReply *setW20(float w20);

    QString crvNam() const;
    QModbusReply *setCrvNam(const QString &crvNam);

    quint16 rmpPt1Tms() const;
    QModbusReply *setRmpPt1Tms(quint16 rmpPt1Tms);

    float rmpDecTmm() const;
    QModbusReply *setRmpDecTmm(float rmpDecTmm);

    float rmpIncTmm() const;
    QModbusReply *setRmpIncTmm(float rmpIncTmm);

    float rmpRsUp() const;
    QModbusReply *setRmpRsUp(float rmpRsUp);

    quint16 snptW() const;
    QModbusReply *setSnptW(quint16 snptW);

    float wRef() const;
    QModbusReply *setWRef(float wRef);

    float wRefStrHz() const;
    QModbusReply *setWRefStrHz(float wRefStrHz);

    float wRefStopHz() const;
    QModbusReply *setWRefStopHz(float wRefStopHz);

    Readonly readOnly() const;

    void processBlockData(const QVector<quint16> blockData) override;

protected:
    void initDataPoints();

private:
    SunSpecFreqWattModel *m_parentModel = nullptr;

    quint16 m_actPt = 0;
    float m_hz1 = 0;
    float m_w1 = 0;
    float m_hz2 = 0;
    float m_w2 = 0;
    float m_hz3 = 0;
    float m_w3 = 0;
    float m_hz4 = 0;
    float m_w4 = 0;
    float m_hz5 = 0;
    float m_w5 = 0;
    float m_hz6 = 0;
    float m_w6 = 0;
    float m_hz7 = 0;
    float m_w7 = 0;
    float m_hz8 = 0;
    float m_w8 = 0;
    float m_hz9 = 0;
    float m_w9 = 0;
    float m_hz10 = 0;
    float m_w10 = 0;
    float m_hz11 = 0;
    float m_w11 = 0;
    float m_hz12 = 0;
    float m_w12 = 0;
    float m_hz13 = 0;
    float m_w13 = 0;
    float m_hz14 = 0;
    float m_w14 = 0;
    float m_hz15 = 0;
    float m_w15 = 0;
    float m_hz16 = 0;
    float m_w16 = 0;
    float m_hz17 = 0;
    float m_w17 = 0;
    float m_hz18 = 0;
    float m_w18 = 0;
    float m_hz19 = 0;
    float m_w19 = 0;
    float m_hz20 = 0;
    float m_w20 = 0;
    QString m_crvNam;
    quint16 m_rmpPt1Tms = 0;
    float m_rmpDecTmm = 0;
    float m_rmpIncTmm = 0;
    float m_rmpRsUp = 0;
    quint16 m_snptW = 0;
    float m_wRef = 0;
    float m_wRefStrHz = 0;
    float m_wRefStopHz = 0;
    Readonly m_readOnly;

};



class SunSpecFreqWattModel : public SunSpecModel
{
    Q_OBJECT
public:

    enum Modena {
        ModenaEnabled = 0x1
    };
    Q_DECLARE_FLAGS(ModenaFlags, Modena)
    Q_FLAG(Modena)

    explicit SunSpecFreqWattModel(SunSpecConnection *connection, quint16 modbusStartRegister, quint16 modelLength, QObject *parent = nullptr);
    ~SunSpecFreqWattModel() override; 

    QString name() const override;
    QString description() const override;
    QString label() const override;


    quint16 actCrv() const;
    QModbusReply *setActCrv(quint16 actCrv);

    ModenaFlags modEna() const;
    QModbusReply *setModEna(ModenaFlags modEna);

    quint16 winTms() const;
    QModbusReply *setWinTms(quint16 winTms);

    quint16 rvrtTms() const;
    QModbusReply *setRvrtTms(quint16 rvrtTms);

    quint16 rmpTms() const;
    QModbusReply *setRmpTms(quint16 rmpTms);

    quint16 nCrv() const;
    quint16 nPt() const;
    qint16 hzSf() const;
    qint16 wSf() const;
    qint16 rmpIncDecSf() const;

protected:
    quint16 m_fixedBlockLength = 10;
    quint16 m_repeatingBlockLength = 58;

    void initDataPoints();
    void processBlockData() override;

private:
    quint16 m_actCrv = 0;
    ModenaFlags m_modEna;
    quint16 m_winTms = 0;
    quint16 m_rvrtTms = 0;
    quint16 m_rmpTms = 0;
    quint16 m_nCrv = 0;
    quint16 m_nPt = 0;
    qint16 m_hzSf = 0;
    qint16 m_wSf = 0;
    qint16 m_rmpIncDecSf = 0;


};

QDebug operator<<(QDebug debug, SunSpecFreqWattModel *model);

#endif // SUNSPECFREQWATTMODEL_H
