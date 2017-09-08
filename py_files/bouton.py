# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    py_files/bouton.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/05 17:01:23 by tnicolas          #+#    #+#              #
#    Updated: 2017/09/05 17:01:23 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import *

# other files
# fenetre.py
# tk_test.py

class Bouton():
    def __init__(self, fen, ino, color='white', width=600, height=500):
        self.fen = fen
        self.ino = ino
        self.width = width
        self.height = height
        self.color = color
        self.c1 = Canvas(self.fen, bg='dark grey', width=self.width,
					height=self.height)
        self.c1.pack(side=TOP)
        self.coord = []
        self.maj = False
        self.data_id = ''

    def mouse_clic(self, event):
        for i in self.coord:
            if (i['x1'] < event.x < i['x2'] and i['y1'] < event.y < i['y2']):
                self.maj = True
                self.data_id = i['id']

    def draw(self):
        self.c1.create_rectangle(0, 0, self.width, self.height, fill=self.color)
        for i in self.coord:
            if (i['color'] == '' and i['bord'] == ''):
                self.c1.create_rectangle(i['x1'], i['y1'], i['x2'], i['y2'])
            elif (i['color'] == '' and i['bord'] != ''):
                self.c1.create_rectangle(i['x1'], i['y1'], i['x2'], i['y2'],
							outline=i['bord'])
            elif (i['color'] != '' and i['bord'] == ''):
                self.c1.create_rectangle(i['x1'], i['y1'], i['x2'], i['y2'],
							fill=i['color'])
            elif (i['color'] != '' and i['bord'] != ''):
                self.c1.create_rectangle(i['x1'], i['y1'], i['x2'], i['y2'],
							fill=i['color'], outline=i['bord'])
            #if (i['text'] != ''):
                #il faut cree text##############################################

    def carre(self, x=0, y=0, width=50, height=50, color='', border_color='',
				text=''):
        if (color == '' and border_color == ''):
            self.c1.create_rectangle(x, y, x+width, y+height)
        elif (color == '' and border_color != ''):
            self.c1.create_rectangle(x, y, x+width, y+height,
						outline=border_color)
        elif (color != '' and border_color == ''):
            self.c1.create_rectangle(x, y, x+width, y+height, fill=color)
        elif (color != '' and border_color != ''):
            self.c1.create_rectangle(x, y, x+width, y+height, fill=color,
						outline=border_color)


    def create(self, id_button, x=0, y=0, width=50, height=50, color='',
				border_color='', dataPress='', dataRelease='', text=''):
        coord_carre = {
            'id' : id_button,
            'x1' : x,
            'y1' : y,
            'x2' : x + width,
            'y2' : y + height,
            'color' : color,
            'bord' : border_color,
            'dataPress' : dataPress,
            'dataRelease' : dataRelease,
            'text' : text
            }
        self.coord.append(coord_carre)

    def remove(self, id_b):
        for i in range(len(self.coord)):
            if (self.coord[i-1]['id'] == id_b):
                del self.coord[i-1]

    def modify(self, id_b, data_name, value):
        for i in range(len(self.coord)):
            if (self.coord[i-1]['id'] == id_b):
                self.coord[i-1][data_name] = value
