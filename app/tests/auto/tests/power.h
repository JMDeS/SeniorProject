#ifndef POWER_H
#define POWER_H

#include"interfaces.h"
//#include <QObject>
//#include <QtCore>
#define LABJACK_U6_DEVICE 0
#define ERROR_NO_DEVICE_FOUND -1

class Power : public iPower
{
//    Q_OBJECT
public:
//    explicit Power(iPower const *parent = 0);
    Power();

    bool power_connected() const { return m_power_connected; }
    void connect() {m_power_connected = false;}
    int voltage() const { return m_voltage; }
    int getDeviceId();
//signals:
//    void voltageChanged(int voltage);

public slots:
    int connectPower(); //on QThread::started() signal
    int readVoltage(); // on voltageChanged signal
    int writeVoltage(double voltage);
    int updateVoltage(double voltage);

private:
    bool m_power_connected = true;
    int m_voltage;
};

#endif // POWER_H
