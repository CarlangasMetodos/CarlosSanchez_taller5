import numpy as np
import matplotlib.pyplot as plt
import imageio
import matplotlib.animation as animation

datos = np.genfromtxt('dat.txt',delimiter=",")
x=np.linspace(0,len(datos),len(datos))
frames,puntos=np.shape(datos)
sz=np.size(datos,1)
fr=np.size(datos,0)

def animate(i):
	plt.cla()
	Dataset=datos[i,:]
	plt.ylim([-1,1]) #Altura de la cuerda
	plt.plot(Dataset)

figura=plt.figure()

#FuncAnimation plotea el gif
gif=animation.FuncAnimation(figura,animate,frames=fr)

#.save para guardarlo y hacerlo funcionar, req writer 
gif.save('cuerda.gif',writer='imagemagick',fps=fr/2)
plt.show()












