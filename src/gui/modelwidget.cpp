#include "modelwidget.h"


ModelWidget::ModelWidget( QWidget* parent, Qt::WindowFlags f )
    : QWidget( parent, f )
{
}

void ModelWidget::loadModel( QString modelName )
{
#if 0
    auto* modelVisu = new ModelVisu( modelName );

    embededViews_ = QWidget::createWindowContainer( modelVisu );

    embededViews_->setMinimumSize( 320, 240 );
    embededViews_->setMaximumSize( 1600, 900 );
    embededViews_->setFocusPolicy( Qt::TabFocus );

    auto currentLayout = layout();
    if ( currentLayout == nullptr )
    {
        QVBoxLayout* layout = new QVBoxLayout;
        setLayout( layout );
    }

    layout()->addWidget( embededViews_ );
#endif
}
