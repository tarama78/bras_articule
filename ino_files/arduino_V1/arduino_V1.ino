/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino_files/arduino_V1.ino                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 17:30:06 by tnicolas          #+#    #+#             */
/*   Updated: 2017/09/03 17:30:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Moteur {
#define RELEASE 0
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3

	int control1;
	int control2;
	int pinVitesse;
	boolean vitBool = true;

	public: Moteur(int ctrl1, int ctrl2, int vit)
	{
		control1 = ctrl1;
		control2 = ctrl2;
		pinVitesse = vit;
	}
	public: Moteur(int ctrl1, int ctrl2)
	{
		control1 = ctrl1;
		control2 = ctrl2;
		vitBool = false;
	}

	void begin()
	{
		pinMode(control1, OUTPUT);
		pinMode(control2, OUTPUT);
		if (vitBool)
		{
			pinMode(pinVitesse, OUTPUT);
			analogWrite(pinVitesse, 255);
		}
	}

	void run(int sens)
	{
		switch (sens)
		{
			case 0:
				digitalWrite(control1, LOW);
				digitalWrite(control2, LOW);
				break;

			case 1:
				digitalWrite(control1, HIGH);
				digitalWrite(control2, LOW);
				break;

			case 2:
				digitalWrite(control1, LOW);
				digitalWrite(control2, HIGH);
				break;

			case 3:
				digitalWrite(control1, HIGH);
				digitalWrite(control2, HIGH);
				break;
		}
	}

	void setSpeed(int vit)
	{
		if (vitBool)
		{
			analogWrite(pinVitesse, vit);
		}
	}
};

Moteur     m_rot(22, 23, 2);
Moteur     m_art1(24, 25, 3);
Moteur     m_art2(28, 29, 5);
Moteur     m_pince(26, 27, 4);
int        i;
char       txt[100];
String     msg_in;

void  setup()
{
	Serial.begin(9600);
	m_rot.begin();
	m_art1.begin();
	m_art2.begin();
	m_pince.begin();
	m_rot.run(BRAKE);
	m_rot.setSpeed(255);
	m_art1.run(BRAKE);
	m_art1.setSpeed(255);
	m_art2.run(BRAKE);
	m_art2.setSpeed(255);
	m_pince.run(BRAKE);
	m_pince.setSpeed(255);
}

void loop()
{
	if (Serial.available())
	{
		i = 0;
		msg_in = "";
		while (i < 4)
		{
			msg_in += (char)Serial.read();
			i++;
		}
		Serial.println(msg_in);
		if (msg_in.equals("m1ron"))
			m_rot.run(BACKWARD);
		else if (msg_in.equals("m1lon"))
			m_rot.run(FORWARD);
		else if (msg_in.equals("m1rof") || msg_in.equals("m1lof"))
			m_rot.run(BRAKE);
		else if (msg_in.equals("m2ron"))
			m_art1.run(BACKWARD);
		else if (msg_in.equals("m2lon"))
			m_art1.run(FORWARD);
		else if (msg_in.equals("m2rof") || msg_in.equals("m2lof"))
			m_art1.run(BRAKE);
		else if (msg_in.equals("m3ron"))
			m_art2.run(BACKWARD);
		else if (msg_in.equals("m3lon"))
			m_art2.run(FORWARD);
		else if (msg_in.equals("m3rof") || msg_in.equals("m3lof"))
			m_art2.run(BRAKE);
		else if (msg_in.equals("m4ron"))
			m_pince.run(BACKWARD);
		else if (msg_in.equals("m4lon"))
			m_pince.run(FORWARD);
		else if (msg_in.equals("m4rof") || msg_in.equals("m4lof"))
			m_pince.run(BRAKE);
		else if (msg_in.equals("allof"))
		{
			m_rot.run(BRAKE);
			m_art1.run(BRAKE);
			m_art2.run(BRAKE);
			m_pince.run(BRAKE);
		}
		else if (msg_in.equals("m1125"))
			m_rot.setSpeed(125);
		else if (msg_in.equals("m1200"))
			m_rot.setSpeed(200);
		else if (msg_in.equals("m1255"))
			m_rot.setSpeed(255);
		else if (msg_in.equals("m2125"))
			m_art1.setSpeed(125);
		else if (msg_in.equals("m200"))
			m_art1.setSpeed(200);
		else if (msg_in.equals("m2255"))
			m_art1.setSpeed(255);
		else if (msg_in.equals("m3125"))
			m_art2.setSpeed(200);
		else if (msg_in.equals("m3200"))
			m_art2.setSpeed(225);
		else if (msg_in.equals("m3255"))
			m_art2.setSpeed(255);
		else if (msg_in.equals("m4125"))
			m_pince.setSpeed(200);
		else if (msg_in.equals("m4200"))
			m_pince.setSpeed(225);
		else if (msg_in.equals("m4255"))
			m_pince.setSpeed(255);
	}
	delay(200);
}
