#include "SpriteSheet.h"
#include "../../Game/Source/DataType.h"
#include "Framework.h"
#include <fstream>

using json = nlohmann::json;

namespace fw
{
    SpriteSheet::SpriteSheet()
    {
        std::ifstream f("Data/Textures/Zelda.json");
        json data = json::parse(f);
        json spriteSheetData = data["sprites"];

        for (int i = 0; i < spriteSheetData.size(); i++)
        {
            json offset;
            json scale;
            json temp;
            temp = spriteSheetData[i];

            std::string name = temp["name"];
            offset = temp["pos"];
            scale = temp["size"];

            spritedetails[name] = new SpriteDetails();
            spritedetails[name]->uvOffset = vec2(offset[0], offset[1]);
            spritedetails[name]->uvScale = vec2(scale[0], scale[1]);
        }
    }

    SpriteSheet::~SpriteSheet()
    {
        for (auto i : spritedetails)
        {
            delete i.second;
        }
    }

    vec2 SpriteSheet::GetScale(std::string s)
    {
        return spritedetails[s]->uvScale;
    }

    vec2 SpriteSheet::GetOffset(std::string s)
    {
        return spritedetails[s]->uvOffset;
    }
}



