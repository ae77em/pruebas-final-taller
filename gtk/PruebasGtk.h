/* 
 * File:   PruebasGtk.h
 * Author: esteban
 *
 * Created on January 25, 2019, 8:46 PM
 */

#ifndef PRUEBASGTK_H
#define	PRUEBASGTK_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/builder.h>

class PruebasGtk {
public:
    PruebasGtk();
    PruebasGtk(const PruebasGtk& orig);
    virtual ~PruebasGtk();
    
    void run(int argc, char** argv);
private:    
    // handlers
    void on_close_button_clicked();
    
    // widgets
    Gtk::Window *pWindow;
    Gtk::Button close_btn;
};

#endif	/* PRUEBASGTK_H */

