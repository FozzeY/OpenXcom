/*
 * Copyright 2010 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_BASE_H
#define OPENXCOM_BASE_H

#include "Target.h"
#include <string>
#include <vector>
#include <map>
#include <string>

class BaseFacility;
class Soldier;
class Craft;
class Item;
class Language;

/**
 * Represents a player base on the globe.
 * Bases can contain facilities, personnel, crafts and equipment.
 */
class Base : public Target
{
private:
	std::string _name;
	std::vector<BaseFacility*> _facilities;
	std::vector<Soldier*> _soldiers;
	std::vector<Craft*> _crafts;
	std::map<std::string, Item*> _items;
	int _scientists, _engineers;
public:
	/// Creates a new base.
	Base();
	/// Cleans up the base.
	~Base();
	/// Gets the base's name.
	std::string getName(Language* lang = 0) const;
	/// Sets the base's name.
	void setName(const std::string &name);
	/// Gets the base's facilities.
	std::vector<BaseFacility*> *getFacilities();
	/// Gets the base's soldiers.
	std::vector<Soldier*> *getSoldiers();
	/// Gets the base's crafts.
	std::vector<Craft*> *getCrafts();
	/// Gets the base's items.
	std::map<std::string, Item*> *getItems();
	/// Sets the base's scientists.
	void setScientists(int scientists);
	/// Sets the base's engineers.
	void setEngineers(int engineers);
	/// Gets the base's available soldiers.
	int getAvailableSoldiers() const;
	/// Gets the base's total soldiers.
	int getTotalSoldiers() const;
	/// Gets the base's available scientists.
	int getAvailableScientists() const;
	/// Gets the base's total scientists.
	int getTotalScientists() const;
	/// Gets the base's available engineers.
	int getAvailableEngineers() const;
	/// Gets the base's total engineers.
	int getTotalEngineers() const;
	/// Gets the base's used living quarters.
	int getUsedQuarters() const;
	/// Gets the base's available living quarters.
	int getAvailableQuarters() const;
	/// Gets the base's used storage space.
	int getUsedStores() const;
	/// Gets the base's available storage space.
	int getAvailableStores() const;
	/// Gets the base's used laboratory space.
	int getUsedLaboratories() const;
	/// Gets the base's available laboratory space.
	int getAvailableLaboratories() const;
	/// Gets the base's used workshop space.
	int getUsedWorkshops() const;
	/// Gets the base's available workshop space.
	int getAvailableWorkshops() const;
	/// Gets the base's used hangars.
	int getUsedHangars() const;
	/// Gets the base's available hangars.
	int getAvailableHangars() const;
	/// Gets the base's defence value.
	int getDefenceValue() const;
	/// Gets the base's short range detection.
	int getShortRangeDetection() const;
	/// Gets the base's long range detection.
	int getLongRangeDetection() const;
	/// Gets the base's crafts of a certain type.
	int getCraftCount(std::string craft) const;
	/// Gets the base's craft maintenance.
	int getCraftMaintenance() const;
	/// Gets the base's personnel maintenance.
	int getPersonnelMaintenance() const;
	/// Gets the base's facility maintenance.
	int getFacilityMaintenance() const;
	/// Gets the base's total monthly maintenance.
	int getMonthlyMaintenace() const;
};

#endif
