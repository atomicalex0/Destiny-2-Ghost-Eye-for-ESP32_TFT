This project started out as a basic Ghost build and quickly became a little more.

The code here will generate a moving ghost eye on a small Waveshare or Sunton ESP32 TFT display that you can use inside of a ghost shell to create a fairly realistic ghost for your desk. Sunton part# is ESP32-2424S012N (non-touch). 
Everyone needs a ghost for their desk, you never know when you are going to need to be revived at work. 

The model STLs are also included here, including a little stand. 

When printing the models, merge the files in your slicer - print them as one unit. If you have a multi-material printer, you can color the appropriate surfaces as you wish. 
Or paint it later. 

I kept the ball separate so that it would be easier to colorize. Then cut the model vertically on the side.to.side center plane, splitting the shell into a front and back.

The Waveshare or Sunton board can be hot-glued into the front of the shell. It must be placed at a 45° angle with the USB C port down and to the left when looking "out" of the eye hole. 

You should put magnets in the corner pockets to keep the two halves of the ghost shell together. Use 2.5x6mm magnets. 

The Waveshare and Sunton boards includes a battery charger which can be driven by the onboard USB C port. The stand STL includes a groove to add a cable to the base. You will have to grind it out a little bit for the Sunton board but it will also look a little nicer. The Sunton board has an integrated power switch which is really nice. It fits a 103450 battery no problem so all day Ghost!

To use the eye_bk_sm.h file, create a folder in your PlatformIO directory called Libraries_extra and then create a folder in that directory called eye_bk_sm.h. Put the library file in that folder with the same name. Then tell PlatformIO to look for the additional libraries. 

Have fun, and eyes up, Guardian!
