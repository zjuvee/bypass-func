
/*
    Free to use, coded by juve <3
*/

#include <utility/filemanager.h>

// crear una carpeta, se puede usar permissions para cambiar algunas boludeces de la carpeta (metodos que no se usan hace 2 años)
void file::createfolder(const string& folderpath)
{

    //DWORD attributes = GetFileAttributesA(folderPath.c_str());
    
	if (exists(folderpath))
	{
		cout << (xorstr_("the folder <") + folderpath + (xorstr_("> already exists!"))) << endl;
		return;
	}

	if (create_directory(folderpath))
	{
		cout << (xorstr_("successfully created!")) << endl;
	}

    //permissions(folderPath,
    //                    fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::others_read,
    //                    fs::perm_options::add);

    //SetFileAttributesA(folderpath.c_str(), attributes | FILE_ATTRIBUTE_HIDDEN);
}

// copiar carpeta, no se en que contexto se usaria pero lo hcie pq estaba alpe2
void file::copyfolder(const string& sourcepath, const string& destPath)
{
    if (!exists(sourcepath))
    {
        cout << (xorstr_("path  ")) << sourcepath << (xorstr_("doesnt exists!")) << endl;
        return;
    }

    path source(sourcepath);
    path dest(destPath);

    path destination = dest / source.filename();

    if (!exists(destination))
    {
        create_directories(destination);
    }

    copy(source, destination, copy_options::recursive);
    cout << (xorstr_("sucessfully copied folder: ")) << destination.filename() << endl;
}

// copiar arcbivo, no se en que contexto se usaria pero lo hcie pq estaba alpe2
void file::copyfile(const string& file, const string& destPath)
{
    path source(file);
    path dest(destPath);
    path destination;

    if (!exists(source))
    {
        cout << (xorstr_("file: ")) << source.filename() << (xorstr_(" doesn't exist!")) << endl;
        return;
    }

    if (dest.has_filename() == false)
    {
        dest = dest.parent_path();
    }

    if (is_directory(dest))
    {
        destination = dest / source.filename();
    }
    else
    {
        destination = dest;
    }

    if (copy_file(source, destination, copy_options::overwrite_existing))
    {
        cout << (xorstr_("successfully copied file: ")) << source.filename() << endl;
    }
    else
    {
        cout << (xorstr_("copy failed: ")) << source.filename() << endl;
    }
}

// lo que dice el nombre de la funcion
void file::deletefile(const string& sourcePath)
{
    path source(sourcePath);

    if (!exists(source))
    {
        cout << (xorstr_("folder doesnt exist")) << endl;
        return;
    }

    if (remove(source))
    {
        cout << (xorstr_("successfully deleted: ")) << source.filename() << endl;
    }
}

void file::cleanfolder(const string& folderPath)
{
    path folder(folderPath);

    if (!exists(folder))
    {
        cout << (xorstr_("folder doesnt exist")) << endl;
    }

    if (!is_directory(folder))
    {
        cout << (xorstr_("is not a folder")) << endl;
    }

    for (const auto& entry : directory_iterator(folder))
    {
        remove_all(entry);
    }

    cout << (xorstr_("the folder ")) << folder.filename() << (xorstr_("has been cleaned!")) << endl;

}

