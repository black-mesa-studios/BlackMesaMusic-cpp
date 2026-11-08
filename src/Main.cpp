#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    auto* layout = new QVBoxLayout(&window);

    auto* label = new QLabel("Not clicked");
    auto* button = new QPushButton("Click me!");

    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(
        button,
        &QPushButton::clicked,
        label,
        [label]()
        {
            label->setText("You clicked the button!");
        }
    );

    window.show();

    return app.exec();
}
