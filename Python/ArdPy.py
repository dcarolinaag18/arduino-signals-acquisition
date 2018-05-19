import serial 
import numpy as np
import matplotlib.pyplot as plt


def Datos(N):
    
    """
    Captura N numero de muestras que provienen del puerto serial.
    
    Parametros
    ----------
    N:    Int.
          Numero de muestras a capturar.
          
    Retornos
    -------    
    Data: Array.
          Datos capturados.
    """
    Ser = serial.Serial('COM3', 115200)
    Dat = []
    
    for Con in range(0, N):
    
        Num = Ser.readline().strip()
        Num = Num.decode('utf-8')
        #print(Num)
        Dat.append(str(Num) +'\n')

    Ser.close()
    
    return Dat


def Guardar(Lista):
    
    """
    Guarda datos de un archivo de texto.
    
    Parametros
    ----------
    Ruta: String.
          Dirrecion del archivo de texto.
    """
    
    Vec = open("Vector.txt","w")
    Vec.writelines(Lista)
    Vec.close()

def Cargar(Ruta):
    
    """
    Carga datos de un archivo de texto.
    
    Parametros
    ----------
    Ruta: String.
          Dirrecion del archivo de texto.
          
    Retornos
    -------    
    Vectro: Array.
          Datos Almacenados.
    """
    Vector =[]
    Doc = open(Ruta,"r")
    
    for Line in Doc.readlines():
        Vector.append((Line))

    Doc.close()

    return Vector


def Graficar(Lista,Fs,N):

    Ts = 1.0/Fs;
    Tf = float(N)/float(Fs)

    x = np.arange(0,Tf,Ts)
    y = Lista[0:len(x)]
    plt.plot(x, y)
    plt.title("Electrocardiograma")
    plt.xlabel("Tiempo")
    plt.ylabel("Milivoltios")
    plt.show()

def main():
    N = 2000
    Fs = 256.0
    
    # +++++ECG
    #Guardar(Datos(N))
    Sen = Cargar('Vector.txt')
    Sen = Sen[0:N]
    Graficar(Sen,Fs,N)

    
    
    
if __name__ == "__main__":
    
    main()
    
