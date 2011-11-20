package org.rstudio.studio.client.common.posixshell;

import org.rstudio.core.client.command.CommandBinder;
import org.rstudio.core.client.command.Handler;
import org.rstudio.core.client.widget.MessageDialog;
import org.rstudio.studio.client.application.Desktop;
import org.rstudio.studio.client.common.GlobalDisplay;
import org.rstudio.studio.client.workbench.commands.Commands;

import com.google.gwt.core.client.GWT;
import com.google.inject.Inject;
import com.google.inject.Singleton;

@Singleton
public class PosixShell
{
   interface Binder extends CommandBinder<Commands, PosixShell> {}
   
   @Inject
   public PosixShell(GlobalDisplay globalDisplay,
                            Commands commands)
   {
      globalDisplay_ = globalDisplay;
      
      if (Desktop.isDesktop())
         commands.showShellDialog().remove();
      
      ((Binder)GWT.create(Binder.class)).bind(commands, this);
      
   }
   
   
   
   @Handler
   public void onShowShellDialog()
   {
      globalDisplay_.showMessage(MessageDialog.INFO,
                                 "Not Yet Implemented",
                                 "This feature is still under construction.");
   }

   
   private final GlobalDisplay globalDisplay_;
}