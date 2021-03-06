/*
 * Settings.hpp
 *
 * Copyright (C) 2009-11 by RStudio, Inc.
 *
 * This program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef CORE_SETTINGS_HPP
#define CORE_SETTINGS_HPP

#include <string>
#include <map>

#include <boost/utility.hpp>

#include <core/FilePath.hpp>

namespace core {

class Error ;

class Settings : boost::noncopyable
{
public:
   Settings() ;
   virtual ~Settings() ;
   // COPYING: boost::noncopyable

   Error initialize(const FilePath& filePath) ;

public:
   void set(const std::string& name, const std::string& value);
   void set(const std::string& name, int value);
   void set(const std::string& name, bool value);

   bool contains(const std::string& name) const;
   std::string get(const std::string& name, 
                   const std::string& defaultValue = std::string()) const;
   int getInt(const std::string& name, int defaultValue = 0) const;
   int getBool(const std::string& name, bool defaultValue = false) const; 

   void beginUpdate();
   void endUpdate();

private:
   void writeSettings() ;

private:
   FilePath settingsFile_ ;
   std::map<std::string, std::string> settingsMap_ ;
   bool updatePending_ ;
   bool isDirty_;
};

}

#endif // CORE_SETTINGS_HPP

