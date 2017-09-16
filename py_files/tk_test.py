# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    py_files/tk_test.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/05 17:01:43 by tnicolas          #+#    #+#              #
#    Updated: 2017/09/05 17:01:43 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial  # bibliothèque permettant la communication série
import time    # pour le délai
from tkinter import *
from bouton import *
from fenetre import *

# other files
# fenetre.py
# bouton.py

fen1 = Tk()

i = 0
try:
    ino = serial.Serial('/dev/ttyACM0', 9600)#######################maybe 0 or 1
    print('/dev/ttyACM0', '\n')
except:
    while i < 10:
        try:
            ino = serial.Serial('/dev/ttyACM'+i, 9600)
            print('/dev/ttyACM'+i, '\n')
            i = 20
        except Exception:
            i += 1

b_quit = Button(fen1, text='QUIT', command=fen1.quit)
b_quit.pack(side=BOTTOM)

b1 = Bouton(fen1, ino)

fenetre = Fenetre(fen1, b1)

fen1.mainloop()
fen1.destroy()
