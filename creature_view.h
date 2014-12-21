/* Copyright (C) 2013-2014 Michal Brzozowski (rusolis@poczta.fm)

   This file is part of KeeperRL.

   KeeperRL is free software; you can redistribute it and/or modify it under the terms of the
   GNU General Public License as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   KeeperRL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
   even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along with this program.
   If not, see http://www.gnu.org/licenses/ . */

#ifndef _CREATURE_VIEW_H
#define _CREATURE_VIEW_H

#include "util.h"

class GameInfo;
class MapMemory;
class ViewIndex;
class Level;

class CreatureView {
  public:
  virtual const MapMemory& getMemory() const = 0;
  virtual void getViewIndex(Vec2 pos, ViewIndex&) const = 0;
  virtual void refreshGameInfo(GameInfo&) const = 0;
  virtual Optional<Vec2> getPosition(bool force) const = 0;
  struct MovementInfo {
    Vec2 from;
    Vec2 to;
    double prevTime;
  };
  virtual Optional<MovementInfo> getMovementInfo() const = 0;
  virtual const Level* getLevel() const = 0;
  virtual double getTime() const = 0;
  virtual vector<const Creature*> getVisibleEnemies() const = 0;

  virtual ~CreatureView() {}
};

#endif
