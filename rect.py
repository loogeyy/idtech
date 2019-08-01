import sensor, image, time
from pyb import UART

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.set_windowing((160,80))
sensor.skip_frames(time = 2000)

arduino = UART(3, 9600)
#clock = time.clock()
color_threshold = ((100, 30, -120, 101, 107, 22))
#((63, 35, -25, 40, -89, 32))
#((63, 24, -25, 69, 36, 47)) afternoon light
#((95, 68, 26, -75, 117, 0))
while(True):
    #clock.tick()
    img = sensor.snapshot()
    objects = img.find_blobs([color_threshold], pixels_threshold = 200, merge = True)
    for object in objects:
        img.draw_rectangle(object.rect())
    if (len(objects) == 0):
            print(ord("0"))
            arduino.write("0")
    elif (len(objects) > 0):
            print(ord("1"))
            arduino.write("1")
            #time.sleep(1000)
