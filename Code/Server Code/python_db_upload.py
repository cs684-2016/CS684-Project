import pymysql

db = pymysql.connect( 'localhost', 'root', '', 'mydb' )
cursor = db.connect()

cursor.execute( 'INSERT INTO `temperature`(`temperature`, `humidity`) VALUES (100,100)' )
db.commit()
db.close()