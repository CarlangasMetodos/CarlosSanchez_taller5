import numpy as np
import matplotlib.pyplot as plt


datos=np.genfromtxt('dat.txt', delimiter=",")
q2=datos[:,0]
p2=datos[:,1]


plt.figure()
plt.scatter(q2,p2)
plt.xlabel('q2')
plt.ylabel('p2')
plt.savefig('caos.pdf')
plt.savefig('caos.png')
plt.show()

#El archivo en pdf no me funcionaba, adjunto tambien uno en .png :(


