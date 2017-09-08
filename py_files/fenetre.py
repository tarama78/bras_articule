# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    py_files/fenetre.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/05 17:01:34 by tnicolas          #+#    #+#              #
#    Updated: 2017/09/05 17:01:34 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from bouton import *
import time

# other files
# bouton.py
# tk_test.py

class Fenetre():
    def __init__(self, fen, b1):
        self.fen = fen
        self.b1 = b1
        self.b1.c1.bind('<ButtonPress-1>', self.gest_event_press)
        self.b1.c1.bind('<ButtonRelease-1>', self.gest_event_release)
        self.basic_fen()

    def gest_event_press(self, event):
        self.b1.mouse_clic(event);
        if (self.b1.maj):
            self.b1.maj = False
            self.act_button_press(self.b1.data_id)

    def gest_event_release(self, event):
        self.b1.mouse_clic(event);
        if (self.b1.maj):
            self.b1.maj = False
            self.act_button_release(self.b1.data_id)

    def send_data_press(self, b_act):
        print("send {} at the arduino".format(b_act['dataPress']))
        self.b1.ino.write(b_act['dataPress'].encode())
        time.sleep(0.05)
        self.b1.ino.write(b_act['dataPress'].encode())

    def send_data_release(self, b_act):
        print("send {} at the arduino".format(b_act['dataRelease']))
        self.b1.ino.write(b_act['dataRelease'].encode())
        time.sleep(0.05)
        self.b1.ino.write(b_act['dataRelease'].encode())

    def send_data_txt(self, data):
        print("send {} at the arduino".format(data))
        self.b1.ino.write(data.encode())
        time.sleep(0.05)
        self.b1.ino.write(data.encode())

    def basic_fen(self):
        #self.b1.create(id, x, y, w, h, color, border_color, data, text)
##### fenetre de base
        self.b1.create('m1sp_indic', 100, 25, 20, 140, color='green',
					border_color='black', text='off')
        self.b1.create("m1sp3", 130, 25, 60, 40, color='green',
					border_color="black", dataPress='m1255', text='off')
        self.b1.create("m1sp2", 130, 75, 60, 40, color='orange',
					border_color="black", dataPress='m1200', text='off')
        self.b1.create("m1sp1", 130, 125, 60, 40, color='yellow',
					border_color="black", dataPress='m1125', text='off')
        self.b1.create("m_rot_r", 100, 175, 90, 90, color='yellow',
					border_color="black", dataPress='m1ron',
					dataRelease='m1rof', text='off')
        self.b1.create("m_rot_l", 100, 275, 90, 90, color='blue',
					border_color="black", dataPress='m1lon',
					dataRelease='m1lof', text='off')
        self.b1.create('m2sp_indic', 200, 25, 20, 140, color='green',
					border_color='black', text='off')
        self.b1.create("m2sp3", 230, 25, 60, 40, color='green',
					border_color="black", dataPress='m2255', text='off')
        self.b1.create("m2sp2", 230, 75, 60, 40, color='orange',
					border_color="black", dataPress='m2200', text='off')
        self.b1.create("m2sp1", 230, 125, 60, 40, color='yellow',
					border_color="black", dataPress='m2125', text='off')
        self.b1.create("m_art1_r", 200, 175, 90, 90, color='yellow',
					border_color="black", dataPress='m2ron',
					dataRelease='m2rof', text='off')
        self.b1.create("m_art1_l", 200, 275, 90, 90, color='blue',
					border_color="black", dataPress='m2lon',
					dataRelease='m2lof', text='off')


        self.b1.create('m3sp_indic', 300, 25, 20, 140, color='green',
					border_color='black', text='off')
        self.b1.create("m3sp3", 330, 25, 60, 40, color='green',
					border_color="black", dataPress='m3255', text='off')
        self.b1.create("m3sp2", 330, 75, 60, 40, color='orange',
					border_color="black", dataPress='m3200', text='off')
        self.b1.create("m3sp1", 330, 125, 60, 40, color='yellow',
					border_color="black", dataPress='m3125', text='off')
        self.b1.create("m_art2_r", 300, 175, 90, 90, color='yellow',
					border_color="black", dataPress='m3ron',
					dataRelease='m3rof', text='off')
        self.b1.create("m_art2_l", 300, 275, 90, 90, color='blue',
					border_color="black", dataPress='m3lon',
					dataRelease='m3lof', text='off')


        self.b1.create('m4sp_indic', 400, 25, 20, 140, color='green',
					border_color='black', text='off')
        self.b1.create("m4sp3", 430, 25, 60, 40, color='green',
					border_color="black", dataPress='m4255', text='off')
        self.b1.create("m4sp2", 430, 75, 60, 40, color='orange',
					border_color="black", dataPress='m4200', text='off')
        self.b1.create("m4sp1", 430, 125, 60, 40, color='yellow',
					border_color="black", dataPress='m4125', text='off')
        self.b1.create("m_pince_r", 400, 175, 90, 90, color='yellow',
					border_color="black", dataPress='m4ron',
					dataRelease='m4rof', text='off')
        self.b1.create("m_pince_l", 400, 275, 90, 90, color='blue',
					border_color="black", dataPress='m4lon',
					dataRelease='m4lof', text='off')


        self.b1.create("m_off", 100, 375, 390, 90, color='red',
					border_color="black", dataPress='allof', text='off')

#####
        self.b1.draw()

    def act_button_press(self, id_b):
        for i in self.b1.coord:
            if (i['id'] == id_b):
                b_act = i
                break
        # self.send_data : enoyer a l'arduino la case data
        # self.b1.remove(b_act['id']) : suppr bouton (on peut changer l'id)
##### action sur les boutons (b_act)
        if (b_act['id'] in ('m_rot_r', 'm_rot_l', 'm_art1_r', 'm_art1_l',
			'm_art2_r', 'm_art2_l', 'm_pince_r', 'm_pince_l')):
            self.send_data_press(b_act)
        elif (b_act['id'] == 'm_off'):
            self.send_data_press(b_act)
        elif (b_act['id'] == 'm1sp1'):
            self.send_data_press(b_act)
            self.b1.modify('m1sp_indic', 'color', 'yellow')
        elif (b_act['id'] == 'm1sp2'):
            self.send_data_press(b_act)
            self.b1.modify('m1sp_indic', 'color', 'orange')
        elif (b_act['id'] == 'm1sp3'):
            self.send_data_press(b_act)
            self.b1.modify('m1sp_indic', 'color', 'green')
        elif (b_act['id'] == 'm2sp1'):
            self.send_data_press(b_act)
            self.b1.modify('m2sp_indic', 'color', 'yellow')
        elif (b_act['id'] == 'm2sp2'):
            self.send_data_press(b_act)
            self.b1.modify('m2sp_indic', 'color', 'orange')
        elif (b_act['id'] == 'm2sp3'):
            self.send_data_press(b_act)
            self.b1.modify('m2sp_indic', 'color', 'green')
        elif (b_act['id'] == 'm3sp1'):
            self.send_data_press(b_act)
            self.b1.modify('m3sp_indic', 'color', 'yellow')
        elif (b_act['id'] == 'm3sp2'):
            self.send_data_press(b_act)
            self.b1.modify('m3sp_indic', 'color', 'orange')
        elif (b_act['id'] == 'm3sp3'):
            self.send_data_press(b_act)
            self.b1.modify('m3sp_indic', 'color', 'green')
        elif (b_act['id'] == 'm4sp1'):
            self.send_data_press(b_act)
            self.b1.modify('m4sp_indic', 'color', 'yellow')
        elif (b_act['id'] == 'm4sp2'):
            self.send_data_press(b_act)
            self.b1.modify('m4sp_indic', 'color', 'orange')
        elif (b_act['id'] == 'm4sp3'):
            self.send_data_press(b_act)
            self.b1.modify('m4sp_indic', 'color', 'green')
#####
        self.b1.draw()

    def act_button_release(self, id_b):
        for i in self.b1.coord:
            if (i['id'] == id_b):
                b_act = i
                break
        # self.send_data : enoyer a l'arduino la case data
        # self.b1.remove(b_act['id']) : suppr bouton (on peut changer l'id)
##### action sur les boutons (b_act)
        if (b_act['id'] in ('m_rot_r', 'm_rot_l', 'm_art1_r', 'm_art1_l',
			'm_art2_r', 'm_art2_l', 'm_pince_r', 'm_pince_l')):
            self.send_data_release(b_act)
#####
        self.b1.draw()
