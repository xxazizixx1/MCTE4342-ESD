Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Write and Read FSR using EEPROM) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, I use FSR as an analog input. The data obtained from the FSR will be write/updated onto the EEPROM of the Arduino.
2. To write the data, we use the codes in the Update_FSR_EEPROM file.
3. The data written onto the EEPROM can be read as the data will be stored inside the EEPROM despite the Arduino being turned off.
4. To read the data, we use the codes in the Read_FSR_EEPROM file.  

Discussion:
1. EEPROM has a limited amount of space. For arduino uno, it is limited to 1 kilobyte, which is very small to store a data. 
2. The read and write cycles on EEPROM are slower compared to the cycles of RAM. 
 