# -*- coding: cp936 -*-
#创建凹多边形，并随机创建一个点，让玩家判断点在多边形内还是外
#作为鉴别机器人的辅助手段。

import sys
from random import *
'''
def createSinglePoly(width,height,no):
	rect = []
	for i in range(height):
		row = ['0']*width
		rect.append(row)
		
	point = randint(0,width/2)
	if point < 6:
		point = 6
	print "point",point
	startx = randint(0,width/5)
	starty = randint(0,height/5)
	stopx = startx
	stopy = starty + 4*height/5
	
	
	pts0 = []
	
	pts = [[0,0]]*point
	pts[0] = [startx,starty]
	for i in range(point-1):
		x = pts[i][0] + randint(0,width/point) + 1
		yoffset = (randint(0,height/point) + 1)
		if randint(0,1) == 0:
			y = pts[i][1] + yoffset
		else:
			y = pts[i][1] - yoffset
		print x,y
		pts[i+1] = [x,y]
	
	pts0 = pts
		
	pts2 = [[0,0]]*point
	pts2[0] = [pts[point-1][0],stopy]	
	
	for i in range(point-1):
		x = pts2[i][0] - randint(0,width/point) - 1
		yoffset = (randint(0,height/point) + 1)
		if randint(0,1) == 0:
			y = pts2[i][1] + yoffset
		else:
			y = pts2[i][1] - yoffset
		pts2[i+1] = [x,y]	
		
	pts0 += pts2
	
	print pts0
'''
def createSinglePoly(width,height,no):
	pnum = 3
	
	rect = [[0 for row in range(width)] for col in range(height)]
	
	row = [[0,0]] * pnum
	i = 0
	xlist = []
	ylist = []
	while True and i < pnum:
		x = randint(3,(width-2)) / 3 * 3 
		y = randint(3,(height/2 - 2)) /3 * 3 
		if [x,y] in row or x in xlist or y in ylist:
			continue
		else:
			row[i] = [x,y]
			xlist.append(x)
			ylist.append(y)
			i = i + 1
			
	
	row.sort(cmp=lambda x,y: x[0] > y[0] and 1 or (x[0] < y[0]) and -1 or 0)
		
	topline = row
	lastx = row[len(row)-1][0]
	lasty = row[len(row)-1][1]
	toplastx = lastx
	topline.append([lastx+2,lasty])	
				
	row = [[0,0]] * pnum
	i = 0
	xlist = []
	ylist = []
	
	while True and i < pnum:
		x = randint(3,(width - 2))/3 * 3 
		y = randint(3,(height/2 - 2)) / 3 * 3 + height/2 
				
		if [x,y] in row or x in xlist or y in ylist:
			continue
		else:
			row[i] = [x,y]	
			xlist.append(x)
			ylist.append(y)
			i = i + 1					
			
					
	row.sort(cmp=lambda x,y: x[0] > y[0] and 1 or (x[0] < y[0]) and -1 or 0)
	
	bottomline = row
	lastx = row[len(row)-1][0]
	lasty = row[len(row)-1][1]
	if lastx == toplastx:
		lastx = lastx + 1
	bottomline.append([lastx+2,lasty])	
		
	print topline
	print bottomline
	
	prept = [0,0]
		
	star = False
	inside = False
	
	for pt in topline:
		if prept == [0,0]:				
			rect[pt[1]][pt[0]] = 1
			prept = pt			
		else:

			for i in range(prept[0],pt[0]+1):
				rect[prept[1]][i] = 1
				if not star and i <> prept[0] and i <> pt[0] and randint(1,50) == 1:
					#draw the star
					if randint(1,100) < 50:
						rect[prept[1] - 1][i] = 2
						inside = False
						star = True						
						print "1"
					else:
						rect[prept[1] + 1][i] = 2
						inside = True
						star = True
						print "2"
			if prept[1] < pt[1]:
				for i in range(prept[1],pt[1]+1):
					rect[i][pt[0]] = 1
					if not star and i <> prept[1] and i <> pt[1] and randint(1,50) == 1:
						#draw the star
						if randint(1,100) < 50:
							rect[i][pt[0]-1] = 2
							inside = True
							star = True
							print "3"
						else:
							rect[i][pt[0]+1] = 2
							inside = False
							star = True							
							print "4"
			else:
				for i in range(pt[1],prept[1]+1):
					rect[i][pt[0]] = 1					
					if not star and i <> pt[1] and i <> prept[1] and randint(1,30) == 1:
						#draw the star
						if randint(1,100) < 50:
							rect[i][pt[0]-1] = 2
							inside = False
							star = True
							print "5"
						else:
							rect[i][pt[0]+1] = 2
							inside = True
							star = True																
							print "6"
			prept = pt
			
	prept = [0,0]
	for pt in bottomline:
		if prept == [0,0]:				
			rect[pt[1]][pt[0]] = 1
			prept = pt			
		else:

			for i in range(prept[0],pt[0]+1):				
				rect[prept[1]][i] = 1
				if not star and i <> prept[0] and i <> pt[0] and randint(1,20) == 1:
					#draw the star
					if randint(1,100) < 50:
						rect[prept[1] - 1][i] = 2
						inside = True
						star = True						
						print "7"
					else:
						rect[prept[1] + 1][i] = 2
						inside = False
						star = True
						print "8"
										
			if prept[1] < pt[1]:
				for i in range(prept[1],pt[1]+1):
					rect[i][pt[0]] = 1		
					if not star and i <> prept[1] and i <> pt[1] and randint(1,10) == 1:
						#draw the star
						if randint(1,100) < 50:
							rect[i][pt[0]-1] = 2
							inside = False
							star = True
							print "9"
						else:
							rect[i][pt[0]+1] = 2
							inside = True
							star = True					
							print "10"
												
			else:
				for i in range(pt[1],prept[1]+1):
					rect[i][pt[0]] = 1
					if not star and i <> pt[1] and i <> prept[1]:
						#draw the star
						if randint(1,100) < 50:
							rect[i][pt[0]-1] = 2
							inside = True
							star = True
							print "11"
						else:
							rect[i][pt[0]+1] = 2
							inside = False
							star = True										
							print "12"
			prept = pt

	if topline[0][0] < bottomline[0][0]:
		for i in range(topline[0][1],bottomline[0][1]+1):
			rect[i][topline[0][0]] = 1
			if not star and i <> topline[0][1] and i <> bottomline[0][1]+1:
				#draw the star
				if randint(1,100) < 50:
					rect[i][topline[0][0]-1] = 2
					inside = False
					star = True
					print "13"
				else:
					rect[i][topline[0][0]+1] = 2
					inside = True
					star = True													
					print "14"
		for i in range(topline[0][0],bottomline[0][0]+1):
			rect[bottomline[0][1]][i] = 1
	else:
		for i in range(bottomline[0][0],topline[0][0]+1):
			rect[topline[0][1]][i] = 1				
			if not star and i<> bottomline[0][0] and i <> topline[0][0]:
				#draw the star
				if randint(1,100) < 50:
					rect[topline[0][1]+1][i] = 2
					inside = True
					star = True
					print "15"
				else:
					rect[topline[0][1]+1][i] = 2
					inside = False
					star = True																
					print "16"
		for i in range(topline[0][1],bottomline[0][1]+1):
			rect[i][bottomline[0][0]] = 1

			
	if topline[len(topline)-1][0] < bottomline[len(bottomline)-1][0]:
		for i in range(topline[len(topline)-1][0],bottomline[len(bottomline)-1][0]+1):
			rect[topline[len(topline)-1][1]][i] = 1				
		for i in range(topline[len(topline)-1][1],bottomline[len(bottomline)-1][1]+1):
			rect[i][bottomline[len(bottomline)-1][0]] = 1		
	else:
		for i in range(topline[len(topline)-1][1],bottomline[len(bottomline)-1][1]+1):
			rect[i][topline[len(topline)-1][0]] = 1
		for i in range(bottomline[len(bottomline)-1][0],topline[len(topline)-1][0]+1):
			rect[bottomline[len(bottomline)-1][1]][i] = 1			

	
	f = file("data/chart"+str(no)+".txt","w+")
							
	for i in range(len(rect)):
		for j in range(len(rect[i])):			
			pt = rect[i][j]
			if pt == 2:
				for k in range(height):
					if k <> i:
						rect[k][j] = 0
				for k in range(width):
					if k <> j:
						rect[i][k] = 0					
				#rect[i][j-1] = 0
				#rect[i][j+1] = 0
				#rect[i-1][j] = 0
				#rect[i+1][j] = 0
				break

	f.write(str(inside))
	f.write("\n")
	
	for row in rect:
		for pt in row:
			if pt == 1:
				#print "■",
				f.write("[31m■[0m")
			elif pt == 0:
				#print "□",
				f.write("□")
			else:
				f.write(""+"[5;33m★"+""+"[0m")
				#print "★",
		#print "\n"
		f.write("\n")
	f.close()
	
	print inside,star

		
		
	
	
		
def createPoly(width,height,number):
	if width < 20 or height < 20:
		return
	if number < 1 or number > 9999:
		return
	for i in range(number):
		createSinglePoly(width,height,i)
		
def usage(app):
	return "python "+app+" width height number"
if __name__ == "__main__":
	if len(sys.argv) <> 4:
		print usage(sys.argv[0])
	else:
		createPoly(int(sys.argv[1]),int(sys.argv[2]),int(sys.argv[3]))