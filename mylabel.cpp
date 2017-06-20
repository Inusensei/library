#include "mylabel.h"


mylabel::mylabel( QWidget * parent )
:QLabel(parent)
{
m_bLeftPress = true;

setMouseTracking( true );
}

void mylabel::slotClicked( bool, QString )
{
qDebug()<<"Clicked";
}

void mylabel::slotmouseMoved( QString )
{
qDebug()<<"slotmouseMoved";
}

void mylabel::mousePressEvent ( QMouseEvent * event )
{
// 如果单击了就触发clicked信号
if ( event->button() == Qt::LeftButton )
{
m_bLeftPress = true;
emit clicked( m_bLeftPress, this->accessibleDescription() );
}
else
{
m_bLeftPress = false;
emit clicked( m_bLeftPress, this->accessibleDescription() );
}

// 将该事件传给父类处理
QLabel::mousePressEvent(event);
}

void mylabel::mouseMoveEvent( QMouseEvent * event )
{
emit mouseMoved( this->accessibleDescription() );

// 将该事件传给父类处理
QLabel::mouseMoveEvent(event);
}
