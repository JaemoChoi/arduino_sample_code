import tkinter as tk
from tkinter import ttk
import serial
import time

PORT = 'COM6'
BAUD = 115200


ser = serial.Serial(PORT, BAUD)
time.sleep(2)
print(f"Connected to {PORT}")

def send_data(data):
    if ser:
        ser.write(data.encode())
        print(f"Sent: {data}")

def update_motor(idx,val):
    angle = int(float(val))
    send_data(f"[{idx}:{angle}]")

def update_led():
    try:
        idx = int(led_id_entry.get())
        r = int(r_entry.get())
        g = int(g_entry.get())
        b = int(b_entry.get())
        send_data(f"({idx}:{r},{g},{b})")
    except ValueError:
        print("Invalid LED Input")


root = tk.Tk()
root.title("TARS Control Pannel v1.0")
root.geometry("600x800")

tk.Label(root, text="--- Actuator Control ---", font=('Arial', 12, 'bold')).pack(pady=10)

motor_frame = tk.Frame(root)
motor_frame.pack()


target_ids = [1, 110, 100]
for i in target_ids:
    f = tk.Frame(motor_frame)
    f.pack(side=tk.TOP , fill=tk.X , padx=10)
    tk.Label(f, text=f"M{i}:", width=4).pack(side=tk.LEFT)
    s = tk.Scale(f, from_=360, to=0, orient=tk.HORIZONTAL, 
                 length=300,
                 width=20,
                 sliderlength=30,
                 command=lambda v , idx=i: update_motor(idx,v))
    s.set(180)
    s.pack(side=tk.LEFT, fill=tk.X, expand=True)

tk.Label(root, text="").pack()

tk.Label(root, text="--- LED RGB Control ---", font=('Arial', 12 , 'bold')).pack(pady=10)

led_frame = tk.Frame(root)
led_frame.pack()

tk.Label(led_frame, text="LED ID:").grid(row=0, column=0)
led_id_entry = tk.Entry(led_frame, width=5)
led_id_entry.insert(0, "0")
led_id_entry.grid(row=0, column=1)

tk.Label(led_frame, text="R:").grid(row=1, column=0)
r_entry = tk.Entry(led_frame, width=5); r_entry.insert(0, "255"); r_entry.grid(row=1, column=1)
tk.Label(led_frame, text="G:").grid(row=1, column=2)
g_entry = tk.Entry(led_frame, width=5); g_entry.insert(0, "255"); g_entry.grid(row=1, column=3)
tk.Label(led_frame, text="B:").grid(row=1, column=4)
b_entry = tk.Entry(led_frame, width=5); b_entry.insert(0, "255"); b_entry.grid(row=1, column=5)

tk.Button(root, text="Apply LED Control", command=update_led, bg="lightblue").pack(pady=10)

root.mainloop()
