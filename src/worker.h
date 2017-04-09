#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QtCore>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

    bool camera_connected() const { return m_camera_connected; }
    bool power_connected() const { return m_power_connected; }
    int voltage() const { return m_voltage; }

signals:
    void voltageChanged(int voltage);
    void frameRecieved(int frame); // TODO: change param type to img format

public slots:
    void connectCamera(); //on QThread::started() signal
    void connectPower(); //on QThread::started() signal


    void readFrame(); // on QTimer::timeout() signal
    void readVoltage(); // on voltageChanged signal

    void processFrame();
    void updateVoltage(int);



private:
    bool m_camera_connected;
    bool m_power_connected;

    int m_voltage;

};

#endif // WORKER_H


/*
 *---NOTES---
 * 1. may be unecessary to read vltage for our purposes
 *      1.a. alternatively use valueChanged(int) SIGNAL
 *              to call setVoltage(int)
 */
