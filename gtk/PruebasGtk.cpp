/* 
 * File:   PruebasGtk.cpp
 * Author: esteban
 * 
 * Created on January 25, 2019, 8:46 PM
 */

#include "PruebasGtk.h"

PruebasGtk::PruebasGtk() : close_btn("Cerrar") { 
    
}

void PruebasGtk::on_close_button_clicked(){
    pWindow->hide();
}

void PruebasGtk::run(int argc, char* argv[]){
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    pWindow = new Gtk::Window();

    close_btn.signal_clicked().connect(
        sigc::mem_fun(*this, &PruebasGtk::on_close_button_clicked)
    );

    pWindow->add(close_btn);

    close_btn.show();    

    app->run(*pWindow);
}

PruebasGtk::PruebasGtk(const PruebasGtk& orig) {
}

PruebasGtk::~PruebasGtk() {
}

