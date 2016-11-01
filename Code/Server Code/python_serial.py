import sys
import serial
import json

if len(sys.argv) <= 1:
	print( 'Not enough arguements passed' )
	sys.exit()
elif len(sys.argv) == 2 :
	with serial.Serial('COM6', 9600, timeout=1) as ser :
		command = sys.argv[1]
		# print( command )
		ser.write( command.encode() )
		data = ser.readline().strip().decode()
		print( json.dumps(data) )
else :
	with serial.Serial('COM6', 9600, timeout=1) as ser :
		command = sys.argv[1] + sys.argv[2]
		# print( command )
		ser.write( command.encode() )
		data = ser.readline().strip().decode()
		print( json.dumps(data) )
