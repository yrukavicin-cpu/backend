# pie_qt.py
import sys, math
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPainter, QColor, QFont, QPen
from PyQt5.QtCore import QRectF, Qt

parts = [25, 65, 10]
cols = [QColor(227,51,51), QColor(44,140,44), QColor(44,192,230)]

class Pie(QWidget):
    def paintEvent(self, e):
        p = QPainter(self)
        p.setRenderHint(QPainter.Antialiasing, True)
        w, h = self.width(), self.height()
        s = min(w, h)*0.8
        rw, rh = s, s*0.8
        x0 = (w-rw)/2
        y0 = (h-rh)/2
        r = QRectF(x0, y0, rw, rh)
        start = 90*16
        total = sum(parts)
        cx, cy = w/2, h/2
        rx, ry = rw/2, rh/2
        p.setPen(Qt.NoPen)
        for i, v in enumerate(parts):
            span = - (v/total)*360*16
            p.setBrush(cols[i])
            p.drawPie(r, int(start), int(span))
            mid_deg = start/16 + span/16/2
            rad = math.radians(mid_deg)
            px = cx + rx*0.7*math.cos(rad)
            py = cy - ry*0.7*math.sin(rad)
            p.setPen(QColor(20,20,20))
            p.setFont(QFont('Helvetica', 14, QFont.Bold))
            t = f'{int(v)}%'
            tw = p.fontMetrics().horizontalAdvance(t)
            th = p.fontMetrics().height()
            p.drawText(int(px - tw/2), int(py + th/4), t)
            start += span
        p.setPen(QPen(QColor(0,0,0), 2))
        p.setBrush(Qt.NoBrush)
        p.drawEllipse(r)

app = QApplication(sys.argv)
w = Pie()
w.setWindowTitle('Еліптична діаграма')
w.resize(640, 480)
w.show()
sys.exit(app.exec_())
