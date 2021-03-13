#!/usr/bin/python3

import tkinter as tk
import tkinter.font
from PIL import ImageTk, Image
import led


class Application(tk.Frame):

    def exit(self):
        self.master.destroy()

    def toggle(self):
        action = self.selected_led.get()
        if action == 'red':
            self.toggler.toggleLED('red')
        elif action == 'green':
            self.toggler.toggleLED('green')
        else:
            self.toggler.toggleLED('blue')

    def createWidgets(self):
        # Prepare fonts
        std_font = tk.font.Font(family='Helvetica', size=12)
        ttl_font = tk.font.Font(family='Helvectic', size=16, weight='bold')

        # Add RPi image
        self.logo = tk.Label(self.master, image=self.img)
        self.logo.pack(side="top", fill="x", pady=15, expand="no")

        # Add Task name label
        self.label = tk.Label()
        self.label['text'] = 'Task 5.2C - Making a GUI'
        self.label['font'] = ttl_font
        self.label.pack(padx=15, pady=10)

        # Add Radiobuttons
        radio_group = tk.Frame(self.master)

        radio_red = tk.Radiobutton(radio_group)
        radio_red['text'] = 'Red'
        radio_red['font'] = std_font
        radio_red['value'] = 'red'
        radio_red['command'] = self.toggle
        radio_red['variable'] = self.selected_led
        radio_red.pack(anchor=tk.W)

        radio_green = tk.Radiobutton(radio_group)
        radio_green['text'] = 'Green'
        radio_green['font'] = std_font
        radio_green['value'] = 'green'
        radio_green['command'] = self.toggle
        radio_green['variable'] = self.selected_led
        radio_green.pack(anchor=tk.W)

        radio_blue = tk.Radiobutton(radio_group)
        radio_blue['text'] = 'Blue'
        radio_blue['font'] = std_font
        radio_blue['value'] = 'blue'
        radio_blue['command'] = self.toggle
        radio_blue['variable'] = self.selected_led
        radio_blue.pack(anchor=tk.W)

        radio_group.pack(padx=0.5, pady=15)

        # Add Exit button
        self.EXIT = tk.Button(self.master)
        self.EXIT['text'] = 'Exit'
        self.EXIT['width'] = 24
        self.EXIT['command'] = self.exit
        self.EXIT.pack(pady=15)

    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        
        self.master = master
        self.master.protocol('WM_WINDOW_DELETE', self.exit)
        self.master.title('SIT210')
        self.pack()

        self.img = ImageTk.PhotoImage(Image.open('logo.png'))
        
        self.toggler = led.ToggleLED()
        self.toggler.toggleLED('red')

        self.selected_led = tk.StringVar()
        self.selected_led.set('red')
        
        self.createWidgets()


root = tk.Tk()
app = Application(master=root)
app.mainloop()
