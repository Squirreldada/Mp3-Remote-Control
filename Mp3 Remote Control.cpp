//加载Arduino内置库
#include <Arduino.h>
#include <pins_arduino.h>
#include <HardwareSerial.h>
#include <wiring_private.h>
#include <binary.h>
#include <Client.h>
#include <IPAddress.h>
#include <new.h>
#include <Platform.h>
#include <Printable.h>
#include <Print.h>
#include <Server.h>
#include <Stream.h>
#include <Udp.h>
#include <USBAPI.h>
#include <USBCore.h>
#include <USBDesc.h>
#include <WCharacter.h>
#include <WString.h>
//加载遥控模块库
#include <RCSwitch.h>

RCSwitch Sender = RCSwitch(); //定义发送端

int pinSender = 10; //设置发送模块信号引脚

void setup() {
	Sender.enableTransmit(pinSender); //设置发送端口为10
//	Serial.begin(9600); //打开串口调试
//设置端口模式
	pinMode(1, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(pinSender, OUTPUT);
}

void loop() {

	if (digitalRead(1)) {
		Sender.send(1, 9);//PP
//		Serial.println(1);
	}
	if (digitalRead(2)) {
		Sender.send(2, 9);//Mode
//		Serial.println(2);
	}
	if (digitalRead(3)) {
		Sender.send(3, 9);//Next
//		Serial.println(3);
	}
	if (digitalRead(4)) {
		Sender.send(4, 9);//Prev
//		Serial.println(4);
	}
	if (digitalRead(5)) {
		Sender.send(5, 9);//V++
//		Serial.println(5);
	}
	if (digitalRead(6)) {
		Sender.send(6, 9);//V--
//		Serial.println(6);
	}
	if (digitalRead(7)) {
		Sender.send(7, 9);//EQ
//		Serial.println(7);
	}
	if (digitalRead(8)) {
		Sender.send(8, 9);//Repeat
//		Serial.println(8);
	}
	if (digitalRead(9)) {
		Sender.send(9, 9);//REC
//		Serial.println(9);
	}

}
