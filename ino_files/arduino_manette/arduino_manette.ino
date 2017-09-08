/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino_files/arduino_manette/arduino_manette.ino      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:16:54 by tnicolas          #+#    #+#             */
/*   Updated: 2017/09/08 10:16:54 by tnicolas         ###   ########.fr       */
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

#define VIT_1 150
#define VIT_2 200
#define VIT_3 255
#define SUCCESS 0
#define ERROR 1

Moteur		mot[4] =
{
	{22, 23, 2},
	{24, 25, 3},
	{28, 29, 5},
	{26, 27, 4}
};
int			i;
int			j;
String		msg_in;
char		char_act;

void  setup()
{
	Serial.begin(9600);
	mot[0].begin();
	mot[1].begin();
	mot[2].begin();
	mot[3].begin();
	mot[0].run(BRAKE);
	mot[0].setSpeed(255);
	mot[1].run(BRAKE);
	mot[1].setSpeed(255);
	mot[2].run(BRAKE);
	mot[2].setSpeed(255);
	mot[3].run(BRAKE);
	mot[3].setSpeed(255);
}

void loop()
{
	if (Serial.available())
	{
                delay(10);
		i = 0;
		msg_in = "";
		while (i < 4)
		{
			msg_in += (char)Serial.read();
			i++;
		}
                Serial.println(msg_in);
		if (msg_correct(msg_in))
		{	
			j = -1;
			while (++j < 4)
			{
				char_act = msg_in.charAt(j);
				if (char_act == '0')
					mot[j].run(BRAKE);
				else if (char_act == '1')
				{
					mot[j].run(FORWARD);
					mot[j].setSpeed(VIT_1);
				}
				else if (char_act == '2')
				{
					mot[j].run(FORWARD);
					mot[j].setSpeed(VIT_2);
				}
				else if (char_act == '3')
				{
					mot[j].run(FORWARD);
					mot[j].setSpeed(VIT_3);
				}
				else if (char_act == '4')
				{
					mot[j].run(BACKWARD);
					mot[j].setSpeed(VIT_1);
				}
				else if (char_act == '5')
				{
					mot[j].run(BACKWARD);
					mot[j].setSpeed(VIT_2);
				}
				else if (char_act == '6')
				{
					mot[j].run(BACKWARD);
					mot[j].setSpeed(VIT_3);
				}
			}
		}
	}
	delay(10);
}

int		msg_correct(String str)
{
	int		i;

	i = -1;
	while (++i < 4)
	{	
		if (!(str.charAt(i) >= '0' && str.charAt(i) <= '6'))
			return (0); //error
	}
	return(1);
}
