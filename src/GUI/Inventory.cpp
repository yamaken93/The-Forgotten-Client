/*
  Tibia CLient
  Copyright (C) 2019 Saiyans King

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "GUI_UTIL.h"
#include "../engine.h"
#include "../GUI_Elements/GUI_Panel.h"
#include "../GUI_Elements/GUI_PanelWindow.h"
#include "../GUI_Elements/GUI_Button.h"
#include "../GUI_Elements/GUI_Icon.h"
#include "../GUI_Elements/GUI_Label.h"
#include "../GUI_Elements/GUI_StaticImage.h"
#include "../map.h"
#include "../game.h"
#include "../creature.h"
#include "Inventory.h"
#include "itemUI.h"

#define INVENTORY_OPTIONS_TITLE "Options"
#define INVENTORY_OPTIONS_DESCRIPTION "Open options"
#define INVENTORY_OPTIONS_EVENTID 1000
#define INVENTORY_HELP_TITLE "Help"
#define INVENTORY_HELP_DESCRIPTION "Open help menu"
#define INVENTORY_HELP_EVENTID 1001
#define INVENTORY_STOP_TITLE "Stop"
#define INVENTORY_STOP_DESCRIPTION "Stop current action"
#define INVENTORY_STOP_EVENTID 1002
#define INVENTORY_QUESTS_TITLE "Quests"
#define INVENTORY_QUESTS_DESCRIPTION "Open quest log"
#define INVENTORY_QUESTS_EVENTID 1003

extern Engine g_engine;
extern Map g_map;
extern Game g_game;

void inventory_Events(Uint32 event, Sint32)
{
	switch(event)
	{
		case INVENTORY_OPTIONS_EVENTID: UTIL_options(); break;
		case INVENTORY_HELP_EVENTID: break;
		case INVENTORY_STOP_EVENTID: break;
		case INVENTORY_QUESTS_EVENTID: break;
	}
}

void UTIL_createInventoryPanel()
{
	GUI_PanelWindow* pPanel = g_engine.getPanel(GUI_PANEL_WINDOW_INVENTORY);
	if(pPanel)
		g_engine.removePanelWindow(pPanel);

	bool minimized = false;
	if(minimized)
	{

	}
	else
	{
		GUI_PanelWindow* newWindow = new GUI_PanelWindow(iRect(0, 0, 172, 170), false, GUI_PANEL_WINDOW_INVENTORY);
		if(g_clientVersion >= 1000)
		{
			GUI_Button* newButton = new GUI_Button(iRect(124, 149, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_STOP_TITLE, 0, INVENTORY_STOP_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_STOP_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
		}
		else if(g_clientVersion >= 790)
		{
			GUI_Button* newButton = new GUI_Button(iRect(124, 81, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_STOP_TITLE, 0, INVENTORY_STOP_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_STOP_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
			newButton = new GUI_Button(iRect(124, 105, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_QUESTS_TITLE, 0, INVENTORY_QUESTS_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_QUESTS_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
			newButton = new GUI_Button(iRect(124, 127, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_OPTIONS_TITLE, 0, INVENTORY_OPTIONS_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_OPTIONS_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
			newButton = new GUI_Button(iRect(124, 149, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_HELP_TITLE, 0, INVENTORY_HELP_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_HELP_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
		}
		else
		{
			GUI_Button* newButton = new GUI_Button(iRect(124, 81, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_STOP_TITLE, 0, INVENTORY_STOP_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_STOP_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
			newButton = new GUI_Button(iRect(124, 105, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_OPTIONS_TITLE, 0, INVENTORY_OPTIONS_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_OPTIONS_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
			newButton = new GUI_Button(iRect(124, 127, GUI_UI_BUTTON_43PX_GRAY_UP_W, GUI_UI_BUTTON_43PX_GRAY_UP_H), INVENTORY_HELP_TITLE, 0, INVENTORY_HELP_DESCRIPTION);
			newButton->setButtonEventCallback(&inventory_Events, INVENTORY_HELP_EVENTID);
			newButton->startEvents();
			newWindow->addChild(newButton);
		}
		GUI_StaticImage* newImage = new GUI_StaticImage(iRect(124, 19, GUI_UI_ICON_COMBAT_OFFENSIVE_DOWN_W, GUI_UI_ICON_COMBAT_OFFENSIVE_DOWN_H), GUI_UI_IMAGE, GUI_UI_ICON_COMBAT_OFFENSIVE_DOWN_X, GUI_UI_ICON_COMBAT_OFFENSIVE_DOWN_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(124, 39, GUI_UI_ICON_COMBAT_BALANCED_UP_W, GUI_UI_ICON_COMBAT_BALANCED_UP_H), GUI_UI_IMAGE, GUI_UI_ICON_COMBAT_BALANCED_UP_X, GUI_UI_ICON_COMBAT_BALANCED_UP_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(124, 59, GUI_UI_ICON_COMBAT_DEFENSIVE_UP_W, GUI_UI_ICON_COMBAT_DEFENSIVE_UP_H), GUI_UI_IMAGE, GUI_UI_ICON_COMBAT_DEFENSIVE_UP_X, GUI_UI_ICON_COMBAT_DEFENSIVE_UP_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(147, 19, GUI_UI_ICON_STAND_DOWN_W, GUI_UI_ICON_STAND_DOWN_H), GUI_UI_IMAGE, GUI_UI_ICON_STAND_DOWN_X, GUI_UI_ICON_STAND_DOWN_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(147, 39, GUI_UI_ICON_FOLLOW_UP_W, GUI_UI_ICON_FOLLOW_UP_H), GUI_UI_IMAGE, GUI_UI_ICON_FOLLOW_UP_X, GUI_UI_ICON_FOLLOW_UP_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(147, 59, GUI_UI_ICON_COMBAT_PVP_UP_W, GUI_UI_ICON_COMBAT_PVP_UP_H), GUI_UI_IMAGE, GUI_UI_ICON_COMBAT_PVP_UP_X, GUI_UI_ICON_COMBAT_PVP_UP_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(8, 4, GUI_UI_ICON_MINIMIZE_WINDOW_UP_W, GUI_UI_ICON_MINIMIZE_WINDOW_UP_H), GUI_UI_IMAGE, GUI_UI_ICON_MINIMIZE_WINDOW_UP_X, GUI_UI_ICON_MINIMIZE_WINDOW_UP_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(8, 128, GUI_UI_STATUS_BACKGROUND_W, GUI_UI_STATUS_BACKGROUND_H), GUI_UI_IMAGE, GUI_UI_STATUS_BACKGROUND_X, GUI_UI_STATUS_BACKGROUND_Y);
		newWindow->addChild(newImage);
		newImage = new GUI_StaticImage(iRect(82, 128, GUI_UI_STATUS_BACKGROUND_W, GUI_UI_STATUS_BACKGROUND_H), GUI_UI_IMAGE, GUI_UI_STATUS_BACKGROUND_X, GUI_UI_STATUS_BACKGROUND_Y);
		newWindow->addChild(newImage);
		GUI_InventoryItem* newInventoryItem = new GUI_InventoryItem(iRect(46, 5, 32, 32), GUI_UI_INVENTORY_HEAD_X, GUI_UI_INVENTORY_HEAD_Y, SLOT_HEAD);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(9, 19, 32, 32), GUI_UI_INVENTORY_NECKLACE_X, GUI_UI_INVENTORY_NECKLACE_Y, SLOT_NECKLACE);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(83, 19, 32, 32), GUI_UI_INVENTORY_BACKPACK_X, GUI_UI_INVENTORY_BACKPACK_Y, SLOT_BACKPACK);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(46, 42, 32, 32), GUI_UI_INVENTORY_ARMOR_X, GUI_UI_INVENTORY_ARMOR_Y, SLOT_ARMOR);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(9, 56, 32, 32), GUI_UI_INVENTORY_LEFT_X, GUI_UI_INVENTORY_LEFT_Y, SLOT_LEFT);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(83, 56, 32, 32), GUI_UI_INVENTORY_RIGHT_X, GUI_UI_INVENTORY_RIGHT_Y, SLOT_RIGHT);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(46, 79, 32, 32), GUI_UI_INVENTORY_LEGS_X, GUI_UI_INVENTORY_LEGS_Y, SLOT_LEGS);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(46, 116, 32, 32), GUI_UI_INVENTORY_FEET_X, GUI_UI_INVENTORY_FEET_Y, SLOT_FEET);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(9, 93, 32, 32), GUI_UI_INVENTORY_RING_X, GUI_UI_INVENTORY_RING_Y, SLOT_RING);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		newInventoryItem = new GUI_InventoryItem(iRect(83, 93, 32, 32), GUI_UI_INVENTORY_AMMO_X, GUI_UI_INVENTORY_AMMO_Y, SLOT_AMMO);
		newInventoryItem->startEvents();
		newWindow->addChild(newInventoryItem);
		GUI_Icons* newIcons = new GUI_Icons(iRect(8, 151, GUI_UI_ICON_STATUS_BAR_W, GUI_UI_ICON_STATUS_BAR_H));
		newWindow->addChild(newIcons);
		/*GUI_Label* newLabel = new GUI_Label(iRect(25, 130, 0, 0), "Atk:", 0, 255, 255, 255);
		newLabel->setAlign(CLIENT_FONT_ALIGN_CENTER);
		newLabel->setFont(CLIENT_FONT_SMALL);
		newWindow->addChild(newLabel);
		newLabel = new GUI_Label(iRect(25, 140, 0, 0), "0", 0, 255, 255, 255);
		newLabel->setAlign(CLIENT_FONT_ALIGN_CENTER);
		newLabel->setFont(CLIENT_FONT_SMALL);
		newWindow->addChild(newLabel);
		newLabel = new GUI_Label(iRect(99, 130, 0, 0), "Def:", 0, 255, 255, 255);
		newLabel->setAlign(CLIENT_FONT_ALIGN_CENTER);
		newLabel->setFont(CLIENT_FONT_SMALL);
		newWindow->addChild(newLabel);
		newLabel = new GUI_Label(iRect(99, 140, 0, 0), "0", 0, 255, 255, 255);
		newLabel->setAlign(CLIENT_FONT_ALIGN_CENTER);
		newLabel->setFont(CLIENT_FONT_SMALL);
		newWindow->addChild(newLabel);*/
		g_engine.addToPanel(newWindow, GUI_PANEL_MAIN);
	}
}

void UTIL_flashQuestsButton()
{

}

void UTIL_flashFollowButton()
{

}

GUI_Icons::GUI_Icons(iRect boxRect, Uint32 internalID)
{
	setRect(boxRect);
	m_internalID = internalID;
}

void GUI_Icons::onMouseMove(Sint32 x, Sint32 y, bool isInsideParent)
{
	if(isInsideParent && m_tRect.isPointInside(x, y))
	{
		Uint32 playerIcons = g_game.getIcons();
		iRect rect = iRect(m_tRect.x1+2, m_tRect.y1+2, 9, 9);
		if(playerIcons & ICON_POISON)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are poisoned");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_BURN)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are burning");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_ENERGY)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are electrified");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_SWORDS)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You may not logout during a fight");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_DRUNK)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are drunk");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_MANASHIELD)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are protected by a magic shield");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_HASTE)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are hasted");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_PARALYZE)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are paralysed");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_DROWNING)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are drowning");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_FREEZING)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are freezing");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_DAZZLED)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are dazzled");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_CURSED)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are cursed");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_PARTY_BUFF)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are strengthened");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_REDSWORDS)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You may not logout or enter a protection zone");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_PIGEON)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are within a protection zone");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_BLEEDING)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are bleeding");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_LESSERHEX)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are suffering from a lesser hex (reduces received healing)");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_INTENSEHEX)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are suffering from an intense hex (reduces damage output, reduces received healing)");
				return;
			}
			rect.x1 += 10;
		}
		if(playerIcons & ICON_GREATEREHEX)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are suffering from a greater hex (reduces maximum hit points, reduces damage output, reduces received healing)");
				return;
			}
			rect.x1 += 10;
		}

		Creature* localPlayer = g_map.getLocalCreature();
		if(!localPlayer)
			return;

		if(g_game.hasGameFeature(GAME_FEATURE_REGENERATION_TIME) && g_game.getPlayerRegeneration() == 0)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are hungry");
				return;
			}
			rect.x1 += 10;
		}

		Uint8 playerSkull = localPlayer->getSkull();
		switch(playerSkull)
		{
			case SKULL_YELLOW:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You may be attacked by other players");
					return;
				}
				rect.x1 += 10;
			}
			break;
			case SKULL_GREEN:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You are a member of a party");
					return;
				}
				rect.x1 += 10;
			}
			break;
			case SKULL_WHITE:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You have attacked an unmarked player");
					return;
				}
				rect.x1 += 10;
			}
			break;
			case SKULL_RED:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You have killed too many unmarked players");
					return;
				}
				rect.x1 += 10;
			}
			break;
			case SKULL_BLACK:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You have excessively killed unmarked players");
					return;
				}
				rect.x1 += 10;
			}
			break;
			case SKULL_ORANGE:
			{
				if(rect.isPointInside(x, y))
				{
					g_engine.showDescription(x, y, "You may suffer revenge from your former victim");
					return;
				}
				rect.x1 += 10;
			}
			break;
			default: break;
		}

		Uint8 playerEmblem = localPlayer->getEmblem();
		if(playerEmblem != GUILDEMBLEM_NONE && playerEmblem <= GUILDEMBLEM_NEUTRAL)
		{
			if(rect.isPointInside(x, y))
			{
				g_engine.showDescription(x, y, "You are involved in a guild war");
				return;
			}
			rect.x1 += 10;
		}
	}
}

void GUI_Icons::render()
{
	Surface* renderer = g_engine.getRender();
	renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_ICON_STATUS_BAR_X, GUI_UI_ICON_STATUS_BAR_Y, m_tRect.x1, m_tRect.y1, m_tRect.x2, m_tRect.y2);
	
	Sint32 posX = m_tRect.x1+2;
	Sint32 posY = m_tRect.y1+2;
	Uint32 playerIcons = g_game.getIcons();
	if(playerIcons & ICON_POISON)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_POISON_X, GUI_UI_STATUS_POISON_Y, posX, posY, GUI_UI_STATUS_POISON_W, GUI_UI_STATUS_POISON_H);
		posX += 10;
	}
	if(playerIcons & ICON_BURN)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_BURN_X, GUI_UI_STATUS_BURN_Y, posX, posY, GUI_UI_STATUS_BURN_W, GUI_UI_STATUS_BURN_H);
		posX += 10;
	}
	if(playerIcons & ICON_ENERGY)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_ENERGY_X, GUI_UI_STATUS_ENERGY_Y, posX, posY, GUI_UI_STATUS_ENERGY_W, GUI_UI_STATUS_ENERGY_H);
		posX += 10;
	}
	if(playerIcons & ICON_SWORDS)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_SWORDS_X, GUI_UI_STATUS_SWORDS_Y, posX, posY, GUI_UI_STATUS_SWORDS_W, GUI_UI_STATUS_SWORDS_H);
		posX += 10;
	}
	if(playerIcons & ICON_DRUNK)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_DRUNK_X, GUI_UI_STATUS_DRUNK_Y, posX, posY, GUI_UI_STATUS_DRUNK_W, GUI_UI_STATUS_DRUNK_H);
		posX += 10;
	}
	if(playerIcons & ICON_MANASHIELD)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_MANASHIELD_X, GUI_UI_STATUS_MANASHIELD_Y, posX, posY, GUI_UI_STATUS_MANASHIELD_W, GUI_UI_STATUS_MANASHIELD_H);
		posX += 10;
	}
	if(playerIcons & ICON_HASTE)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_HASTE_X, GUI_UI_STATUS_HASTE_Y, posX, posY, GUI_UI_STATUS_HASTE_W, GUI_UI_STATUS_HASTE_H);
		posX += 10;
	}
	if(playerIcons & ICON_PARALYZE)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_PARALYZE_X, GUI_UI_STATUS_PARALYZE_Y, posX, posY, GUI_UI_STATUS_PARALYZE_W, GUI_UI_STATUS_PARALYZE_H);
		posX += 10;
	}
	if(playerIcons & ICON_DROWNING)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_DROWNING_X, GUI_UI_STATUS_DROWNING_Y, posX, posY, GUI_UI_STATUS_DROWNING_W, GUI_UI_STATUS_DROWNING_H);
		posX += 10;
	}
	if(playerIcons & ICON_FREEZING)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_FREEZING_X, GUI_UI_STATUS_FREEZING_Y, posX, posY, GUI_UI_STATUS_FREEZING_W, GUI_UI_STATUS_FREEZING_H);
		posX += 10;
	}
	if(playerIcons & ICON_DAZZLED)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_DAZZLED_X, GUI_UI_STATUS_DAZZLED_Y, posX, posY, GUI_UI_STATUS_DAZZLED_W, GUI_UI_STATUS_DAZZLED_H);
		posX += 10;
	}
	if(playerIcons & ICON_CURSED)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_CURSED_X, GUI_UI_STATUS_CURSED_Y, posX, posY, GUI_UI_STATUS_CURSED_W, GUI_UI_STATUS_CURSED_H);
		posX += 10;
	}
	if(playerIcons & ICON_PARTY_BUFF)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_BUFF_X, GUI_UI_STATUS_BUFF_Y, posX, posY, GUI_UI_STATUS_BUFF_W, GUI_UI_STATUS_BUFF_H);
		posX += 10;
	}
	if(playerIcons & ICON_REDSWORDS)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_PZLOCK_X, GUI_UI_STATUS_PZLOCK_Y, posX, posY, GUI_UI_STATUS_PZLOCK_W, GUI_UI_STATUS_PZLOCK_H);
		posX += 10;
	}
	if(playerIcons & ICON_PIGEON)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_PIGEON_X, GUI_UI_STATUS_PIGEON_Y, posX, posY, GUI_UI_STATUS_PIGEON_W, GUI_UI_STATUS_PIGEON_H);
		posX += 10;
	}
	if(playerIcons & ICON_BLEEDING)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_BLEEDING_X, GUI_UI_STATUS_BLEEDING_Y, posX, posY, GUI_UI_STATUS_BLEEDING_W, GUI_UI_STATUS_BLEEDING_H);
		posX += 10;
	}
	if(playerIcons & ICON_LESSERHEX)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_LESSERHEX_X, GUI_UI_STATUS_LESSERHEX_Y, posX, posY, GUI_UI_STATUS_LESSERHEX_W, GUI_UI_STATUS_LESSERHEX_H);
		posX += 10;
	}
	if(playerIcons & ICON_INTENSEHEX)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_INTENSEHEX_X, GUI_UI_STATUS_INTENSEHEX_Y, posX, posY, GUI_UI_STATUS_INTENSEHEX_W, GUI_UI_STATUS_INTENSEHEX_H);
		posX += 10;
	}
	if(playerIcons & ICON_GREATEREHEX)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_GREATEREHEX_X, GUI_UI_STATUS_GREATEREHEX_Y, posX, posY, GUI_UI_STATUS_GREATEREHEX_W, GUI_UI_STATUS_GREATEREHEX_H);
		posX += 10;
	}

	Creature* localPlayer = g_map.getLocalCreature();
	if(!localPlayer)
		return;

	if(g_game.hasGameFeature(GAME_FEATURE_REGENERATION_TIME) && g_game.getPlayerRegeneration() == 0)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_HUNGRY_X, GUI_UI_STATUS_HUNGRY_Y, posX, posY, GUI_UI_STATUS_HUNGRY_W, GUI_UI_STATUS_HUNGRY_H);
		posX += 10;
	}

	Uint8 playerSkull = localPlayer->getSkull();
	switch(playerSkull)
	{
		case SKULL_YELLOW:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_YELLOWSKULL_X, GUI_UI_STATUS_YELLOWSKULL_Y, posX, posY, GUI_UI_STATUS_YELLOWSKULL_W, GUI_UI_STATUS_YELLOWSKULL_H);
			posX += 10;
		}
		break;
		case SKULL_GREEN:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_GREENSKULL_X, GUI_UI_STATUS_GREENSKULL_Y, posX, posY, GUI_UI_STATUS_GREENSKULL_W, GUI_UI_STATUS_GREENSKULL_H);
			posX += 10;
		}
		break;
		case SKULL_WHITE:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_WHITESKULL_X, GUI_UI_STATUS_WHITESKULL_Y, posX, posY, GUI_UI_STATUS_WHITESKULL_W, GUI_UI_STATUS_WHITESKULL_H);
			posX += 10;
		}
		break;
		case SKULL_RED:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_REDSKULL_X, GUI_UI_STATUS_REDSKULL_Y, posX, posY, GUI_UI_STATUS_REDSKULL_W, GUI_UI_STATUS_REDSKULL_H);
			posX += 10;
		}
		break;
		case SKULL_BLACK:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_BLACKSKULL_X, GUI_UI_STATUS_BLACKSKULL_Y, posX, posY, GUI_UI_STATUS_BLACKSKULL_W, GUI_UI_STATUS_BLACKSKULL_H);
			posX += 10;
		}
		break;
		case SKULL_ORANGE:
		{
			renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_ORANGOSKULL_X, GUI_UI_STATUS_ORANGOSKULL_Y, posX, posY, GUI_UI_STATUS_ORANGOSKULL_W, GUI_UI_STATUS_ORANGOSKULL_H);
			posX += 10;
		}
		break;
		default: break;
	}

	Uint8 playerEmblem = localPlayer->getEmblem();
	if(playerEmblem != GUILDEMBLEM_NONE && playerEmblem <= GUILDEMBLEM_NEUTRAL)
	{
		renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_STATUS_GUILDWAR_X, GUI_UI_STATUS_GUILDWAR_Y, posX, posY, GUI_UI_STATUS_GUILDWAR_W, GUI_UI_STATUS_GUILDWAR_H);
		posX += 10;
	}
}

GUI_InventoryItem::GUI_InventoryItem(iRect boxRect, Sint32 skinX, Sint32 skinY, Uint8 slot, Uint32 internalID)
{
	setRect(boxRect);
	m_skinX = skinX;
	m_skinY = skinY;
	m_slot = slot;
	m_internalID = internalID;
}

void* GUI_InventoryItem::onAction(Sint32, Sint32)
{
	ItemUI* item = g_game.getInventoryItem(m_slot);
	if(item)
		return SDL_reinterpret_cast(void*, item);

	return NULL;
}

void GUI_InventoryItem::onMouseMove(Sint32 x, Sint32 y, bool isInsideParent)
{
	if(g_engine.getAction() == CLIENT_ACTION_MOVEITEM)
	{
		if(isInsideParent && m_tRect.isPointInside(x, y))
			m_selected = true;
		else
			m_selected = false;
	}
}

void GUI_InventoryItem::onLMouseDown(Sint32 x, Sint32 y)
{
	ItemUI* item = g_game.getInventoryItem(m_slot);
	if(item)
	{
		Position& position = item->getCurrentPosition();
		g_engine.setActionData(CLIENT_ACTION_FIRST, 0, item->getID(), position.x, position.y, position.z, 0);
		g_engine.setActionData(CLIENT_ACTION_SECOND, 0, item->getItemCount(), 0, 0, 0, 0);
		g_engine.enableMoveItem(x, y);
	}

	g_engine.setAction(CLIENT_ACTION_LEFTMOUSE);
}

void GUI_InventoryItem::onLMouseUp(Sint32, Sint32)
{
	if(g_engine.getAction() == CLIENT_ACTION_MOVEITEM && m_selected)
	{
		g_engine.initMove(0xFFFF, SDL_static_cast(Uint16, m_slot)+1, 0);
		g_engine.setAction(CLIENT_ACTION_NONE);
	}
}

void GUI_InventoryItem::onRMouseDown(Sint32, Sint32)
{
	g_engine.setAction(CLIENT_ACTION_RIGHTMOUSE);
}

void GUI_InventoryItem::render()
{
	Surface* renderer = g_engine.getRender();
	renderer->drawPicture(GUI_UI_IMAGE, GUI_UI_INVENTORY_EMPTY_X, GUI_UI_INVENTORY_EMPTY_Y, m_tRect.x1-1, m_tRect.y1-1, m_tRect.x2+2, m_tRect.y2+2);

	ItemUI* item = g_game.getInventoryItem(m_slot);
	if(item)
		item->render(m_tRect.x1, m_tRect.y1, m_tRect.y2);
	else
		renderer->drawPicture(GUI_UI_IMAGE, m_skinX, m_skinY, m_tRect.x1, m_tRect.y1, m_tRect.x2, m_tRect.y2);

	if(m_selected)
	{
		if(g_engine.getAction() != CLIENT_ACTION_MOVEITEM)
		{
			m_selected = false;
			return;
		}

		renderer->drawRectangle(m_tRect.x1-1, m_tRect.y1-1, m_tRect.x2+2, m_tRect.y2+2, 255, 255, 255, 255);
	}
}