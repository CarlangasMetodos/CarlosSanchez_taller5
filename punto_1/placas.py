import numpy as np
import matplotlib.pyplot as plt


datos = np.loadtxt('data.txt',delimiter=",")
V= datos[:,0]
Ex= datos[:,1]
Ey=datos[:,2]


dim=np.linspace(0,5,512) #Dimensiones en x y y de la region de las placas

#plt.imshow(V)
#plt.streamplot(dim,dim,Ex,Ey)
#plt.savefig('placas.pdf')

plt.figure()
plt.plot(Ex,Ey)
plt.show()
