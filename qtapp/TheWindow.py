from menu.TheMenu import TheMenu
from picture.Pic import Image
from PyQt6.QtWidgets import QMainWindow, QLabel, QFileDialog, QWidget, QHBoxLayout
from PyQt6.QtGui import QAction
from PyQt6.QtCore import Qt 

class TheWindow(QMainWindow):

    def __init__(self, parent = None):
        super().__init__(parent)
        self.setGeometry(200,100,1000,500)
        self.createCentalWidget()
        self.menuBar = TheMenu(self)
        self.menuBar.addLoadMenuActionHandler(self.setLoadText)
        self.menuBar.addSaveMenuActionHandler(self.setSaveText)

        self.layout = QHBoxLayout(self.centralWidget)
        self.layout.setContentsMargins(50,0,50,0)
        self.leftImage = Image()
        self.layout.addWidget(self.leftImage)
        self.rightImage = Image()
        self.rightImage.playerButton.setText("Player2")
        self.layout.addStretch()
        
        self.layout.addWidget(self.rightImage)


        
    def createCentalWidget(self):
        self.centralWidget = QLabel("def text")
        self.centralWidget.setAlignment( Qt.AlignmentFlag.AlignCenter)
        self.setCentralWidget(self.centralWidget)

    
    def setLoadText(self):
        self.centralWidget.setText("Clicked on State->Load menu item")

    def setSaveText(self):
        self.centralWidget.setText("Clicked on State->Save menu item")
    

    def openFile(self):
        file = QFileDialog(self)
        fileName = file.getOpenFileName()
        #if file.exec_():
           # file