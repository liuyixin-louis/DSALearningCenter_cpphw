#include "customscene.h"
#include <QDebug>

CustomScene::CustomScene(QObject *parent):QGraphicsScene(parent)
{
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "CustomScene::mousePressEvent";
    QGraphicsScene::mousePressEvent(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "CustomScene::mouseReleaseEvent";
    QGraphicsScene::mouseReleaseEvent(event);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "CustomScene::mouseMoveEvent";
    QGraphicsScene::mouseMoveEvent(event);
}

void CustomScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "CustomScene::dragEnterEvent";
    QGraphicsScene::dragEnterEvent(event);
}

void CustomScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "CustomScene::dragLeaveEvent";
    QGraphicsScene::dragLeaveEvent(event);
}

void CustomScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "CustomScene::dragMoveEvent";
    QGraphicsScene::dragMoveEvent(event);
}

void CustomScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "CustomScene::dropEvent";
    QGraphicsScene::dropEvent(event);
}
