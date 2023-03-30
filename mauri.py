import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button
import numpy as np
import pandas as pd

def demanda():
    figura = plt.figure()
    figura.suptitle('Grafico de Demanda')
    precofx = np.arange(99, 179, 10)
    qntfx = np.arange(12.292, 8.292, -0.5)

    tabela = pd.read_csv("D:\demanda.csv")
    demanda = tabela[['Preco','Demanda']]
    demanda2 = tabela[['Preco','Aumento']]
    column_labels= ['Preco','Demanda']

    figura.add_subplot(221)
    plt.plot(tabela['Demanda'], tabela['Preco'], label='A', color='k')
    plt.xlabel('Quantidade')
    plt.ylabel('Preço')
    plt.legend()
    plt.scatter(qntfx[3],precofx[3], color='b')


    df= pd.DataFrame(demanda, columns=['Preco','Demanda'])
    table = plt.table(
            cellText=df.values,
            colLabels=column_labels,
            loc="right")

    table.scale(.8, .8)


    figura.add_subplot(223)
    qnt = np.arange(13.781, 9.781, -0.5)

    plt.plot(tabela['Demanda'], tabela['Preco'], label='A', color='k')
    plt.plot(tabela['Aumento'], tabela['Preco'], label='B', color='r')
    plt.xlabel('Quantidade')
    plt.ylabel('Preço')

    plt.legend()
    plt.scatter(qnt[3],precofx[3], color='b')

    df2 = pd.DataFrame(demanda2, columns= ['Preco','Aumento'])
    tab = plt.table(
            cellText=df2.values,
            colLabels=column_labels,
            loc="right")
    tab.scale(.8, .8) 
    plt.show()



def oferta():
    figura = plt.figure()
    figura.suptitle('Grafico de Oferta')
    precofx = np.arange(99, 179, 10)
    qntfx = np.arange(629.2, 1429.2, 100)

    tabela = pd.read_csv("D:\oferta.csv")
    oferta = tabela[['Preco','Oferta']]
    oferta2 = tabela[['Preco','Aumento']]
    column_labels= ['Preco','Oferta']

    figura.add_subplot(221)
    plt.plot(tabela['Oferta'], tabela['Preco'], label='A', color='k')
    plt.xlabel('Quantidade')
    plt.ylabel('Preço')
    plt.legend()
    plt.scatter(qntfx[3],precofx[3], color='b')


    df= pd.DataFrame(oferta, columns=['Preco','Oferta'])
    table = plt.table(
            cellText=df.values,
            colLabels=column_labels,
            cellLoc='center',
            loc="right")

    table.scale(.8, .8)

    figura.add_subplot(223)
    qnt = np.arange(842.768, 1642.768, 100)

    plt.plot(tabela['Oferta'], tabela['Preco'], label='A', color='k')
    plt.plot(tabela['Aumento'], tabela['Preco'], label='B', color='r')
    plt.xlabel('Quantidade')
    plt.ylabel('Preço')

    plt.legend()
    plt.scatter(qnt[3],precofx[3], color='b')

    df2 = pd.DataFrame(oferta2, columns= ['Preco','Aumento'])
    tab = plt.table(
            cellText=df2.values,
            colLabels=column_labels,
            cellLoc='center',
            loc="right")
    tab.scale(.8, .8) 

    plt.show()

def mercado():

    figura = plt.figure(figsize=(40,40))
    figura.suptitle('Grafico de Mercado')
    boly = np.arange(99, 179, 10)
    bolx = np.arange(1229200, 829200, -50000)

    tabela = pd.read_csv("D:\Mercado.csv")

    mercado = tabela[['Preco','Demanda','Oferta','Status']]
    column_labels= ['Preco','Demanda','Oferta','Status de Mercado']

    figura.add_subplot(221)
    plt.plot(tabela['Demanda'], tabela['Preco'], label='A', color='k')
    plt.plot(tabela['Oferta'], tabela['Preco'], label='B', color='r')
    plt.xlabel('Quantidade')
    plt.ylabel('Preço')
    plt.legend()



    df= pd.DataFrame(mercado, columns=['Preco','Demanda','Oferta','Status'])
    table = plt.table(
            cellText=df.values,
            colLabels=column_labels,
            colWidths= [0.09] * 4,
            cellLoc='center',
            loc="right")
    table.set_fontsize(15.0)
    table.scale(4, 8)
    
    plt.show()












axButton1 = plt.axes([0.25, .8, 0.5, 0.1])
btn1 = Button(axButton1, 'Grafico de Demanda')

def btndemanda(event):
    demanda()
btn1.on_clicked(btndemanda)

axButton2 = plt.axes([0.25, .65, 0.5, 0.1])
btn2 = Button(axButton2, 'Grafico de Oferta')

def btnoferta(event):
    oferta()
btn2.on_clicked(btnoferta)

axButton3 = plt.axes([0.25, .5, 0.5, 0.1])
btn3 = Button(axButton3, 'Grafico de Mercado')

def btnmercado(event):
    mercado()
btn3.on_clicked(btnmercado)

plt.show()