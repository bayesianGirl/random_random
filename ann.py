import xml.dom.minidom as domi
import cv2
import numpy
from math import sin, cos
doc= domi.parse('10.xml')
points= doc.getElementsByTagName('point')
# print(points)
x=[]
for x_ in points:
	x.append(float(x_.getAttribute('x')))
y=[]
for y_ in points:
	y.append(float(y_.getAttribute('y')))

transformationMat= numpy.array([[-137.87177, 232.45399, 632490.25],[552.74329, 469.87775, -7879.8423],[-0.22495107, 0.86817008, 1031.9688]])
print(transformationMat)
Matrix= numpy.array([[[500,0]]],  dtype=numpy.float32)
srcPoints=cv2.perspectiveTransform(Matrix,transformationMat);
print(srcPoints)


