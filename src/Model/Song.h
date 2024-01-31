#ifndef SONG_H
#define SONG_H

#include <Utility/NeteaseCloudMusic>
#include <Service/NeteaseCloudMusic/Response/SongInfoEntity.h>

struct Song {
    Song() = default;
    Song(const SongInfoEntity& entity): id(entity.id), name(entity.name), album(entity.album.name), imgUrl(entity.album.picUrl) {
        if (!entity.aliases.isEmpty())
            alias = entity.aliases.front();
        else
            alias = "";
        artists = "";
        for(const auto& artist: entity.artists) {
            artists += artist.name + u'，';
        }
        artists.removeLast();
    }
    SongId id;
    QString name;
    QString alias;
    QString artists;
    QString album;
    QString imgUrl;
};

#endif // SONG_H