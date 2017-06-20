#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <Qt>

class mylabel : public QLabel {
    Q_OBJECT
    public:
    mylabel( QWidget * parent = 0 );
    ~mylabel() {}

    signals:
    void clicked( bool, QString );
    void mouseMoved( QString );

    public slots:
    void slotClicked( bool m_bLeftPress, QString accessibleDescription );
    void slotmouseMoved( QString accessibleDescription );

    protected:
    void mousePressEvent ( QMouseEvent * event ) ;
    void mouseMoveEvent( QMouseEvent * event );

    private:
    bool m_bLeftPress;
};



#endif // MYLABEL_H
