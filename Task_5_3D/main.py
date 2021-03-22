import tkinter as tk
import tkinter.font
from tkinter.scrolledtext import ScrolledText
from PIL import ImageTk, Image
import morse

class Application(tk.Frame):

    def __init__(self, pin, master=None):
        tk.Frame.__init__(self, master)
        
        self.master = master
        self.master.protocol('WM_WINDOW_DELETE', self.exit)
        self.master.title('SIT210 - Embedded Systems Development')
        self.pack()

        self.img = ImageTk.PhotoImage(Image.open('logo.png'))
        self.createWidgets()

        self.blinker = morse.Morse(pin)

    def exit(self):
        self.master.destroy()

    def enterMessage(self):
        message = self.input_box.get('1.0', tk.END)
        self.blinker.blinkMessage(message)

    def createWidgets(self):
        # Prepare fonts
        std_font = tk.font.Font(family='Helvetica', size=12)
        ttl_font = tk.font.Font(family='Helvectic', size=16, weight='bold')

        # Add RPi image
        self.logo = tk.Label(self.master, image=self.img)
        self.logo.pack(side="top", fill="x", pady=15, expand="no")

        # Add Task name label
        self.label = tk.Label()
        self.label['text'] = 'Task 5.3D - Blink Morse Code'
        self.label['font'] = ttl_font
        self.label.pack(padx=15, pady=10)

        # Add textbox label
        self.entry_label = tk.Label()
        self.entry_label['text'] = 'Enter text to blink'
        self.entry_label['font'] = std_font
        self.entry_label['anchor'] = tk.W
        self.entry_label.pack(padx=15, fill='both')

        # Add textbox
        self.input_box = ScrolledText()
        self.input_box['width'] = 40
        self.input_box['height'] = 5
        self.input_box['wrap'] = tk.WORD
        self.input_box.pack(padx=15, fill='both')
        self.input_box.focus()

        # Add Enter button
        self.Enter = tk.Button(self.master)
        self.Enter['text'] = 'Enter'
        self.Enter['width'] = 20
        self.Enter['command'] = self.enterMessage
        self.Enter.pack(side=tk.LEFT, padx=15, pady=15)

        # Add Exit button
        self.Exit = tk.Button(self.master)
        self.Exit['text'] = 'Exit'
        self.Exit['width'] = 20
        self.Exit['command'] = self.exit
        self.Exit.pack(side=tk.LEFT, padx=10, pady=15)

if __name__ == '__main__':
    root = tk.Tk()
    app = Application(10, master=root)
    app.mainloop()
