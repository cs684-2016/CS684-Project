import time
import sys
import serial
import json

if len(sys.argv) >= 4:
	print( json.dumps('Timer set') )
	t = int( sys.argv[1] )
	time.sleep(t)
	with serial.Serial( 'COM6', 9600, timeout=1 ) as ser :
		command = sys.argv[2] + sys.argv[3];
		# print( command )
		ser.write( command.encode() )
		data = ser.readline().strip().decode()
		print( json.dumps(data) )
		sys.stdout.flush()
else :
	print( json.dumps('No arguement passed') )

# print( json.dumps('hello') )