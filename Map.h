#ifndef MAP_H__
#define MAP_H__

constexpr size_t sizeX = 100;
constexpr size_t sizeY = 100;

class Map
{
public:

	static Map* getMap()
	{
		static Map *m_map;
		if (m_map == nullptr)
			m_map = new Map;
		
		return m_map;
	}
	unsigned char mapMatrix[sizeX+2][sizeY+2];
	const size_t sizeX = 100;
	const size_t sizeY = 100;

private:
	Map() { };
};

Map::Map()
{
	for (size_t i = 0; i < sizeX + 2; ++i)
	{
		for (size_t j = 0; j < sizeY + 2; ++j)
		{
			if (i == 0 || j == 0 || i == sizeX + 1 || j == sizeY + 1)
			{
				mapMatrix[i][j] == 0;
			}
		}
	}
}

#endif