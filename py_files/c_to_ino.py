# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    py_files/c_to_ino.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/05 17:01:29 by tnicolas          #+#    #+#              #
#    Updated: 2017/09/05 17:01:30 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class C_to_Ino():
    def __init__(self, ino, filename):
        self.ino = ino
		self.filename = filename
		self.file = None
		self.file_content = ''
        self.maj = False
        self.data = ''

	def open(self):
		self.file = open(self.filename, 'rw')

	def loop(self):
		while (self.data != 'end'):
			self.file_content = self.file.readlines()
			if (self.file_content != '')
				
			time.sleep(0.01)

    def send_data_(self):
        print("send {} at the arduino".format(self.data))
        self.b1.ino.write(self.data.encode())
        time.sleep(0.05)
        self.b1.ino.write(self.data.encode())
