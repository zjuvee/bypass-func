
/*
    Free to use, coded by juve <3
*/

#include <utility/filemanager.h>
#include <utility/console.h>
#include <utility/services.h>
#include <utility/regedit.h>
#include <utility/misc.h>
#include <memory/aob.h>

// puse algunos ejemplo de como funcionan las funciones, ahi depende de cada uno que carajo va a hacer con esto
int main()
{
	aobscan aob;
	file file;
	console cmd;
	services svc;
	misc misc;
	regedit reg;

	//aob.stringprocess(xorstr_("lsass.exe"));
	//aob.stringservice(xorstr_("dwm.exe"));
	//aob.stringservice(xorstr_("dnscache"));
	//aob.stringservice(xorstr_("dps"));
	
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\Shell\\");
	//reg.regdelete("SYSTEM\\ControlSet001\\Control\\Session Manager\\AppCompatCache\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows Search\\VolumeInfoCache\\");
	//reg.regdelete("SOFTWARE\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\CurrentVersion\\TrayNotify\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\CurrentVersion\\Explorer\\FeatureUsage\\AppSwitched\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explore\\FeatureUsage\\ShowJumpView\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Compatibility Assistant\\Store\\");
	//reg.regdelete("Software\\WinRAR\\ArcHistory\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RecentDocs\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\DirectInput\\");
	//reg.regdelete("SYSTEM\\MountedDevices\\");
	//reg.regdelete("SOFTWARE\\AMD\\HKIDs");
	//reg.regdelete("SOFTWARE\\Microsoft\\CurrentVersion\\Explorer\\ComDlg32\\LastVisitedPidlMRU\\");
	//reg.regdelete("Local Settings\\Software\\Microsoft\\Windows\\Shell\\MuiCache\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\WordWheelQuery\\");
	//reg.regdelete("Local Settings\\Software\\Microsoft\\Windows\\Shell\\MuiCache\\");
	//reg.regdelete("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\TypedPaths\\");
	//reg.regdelete("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\OCS\\");
	//reg.regdelete("SOFTWARE\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\Shell\\BagMRU\\");

	//svc.stop();
	//svc.start();

	//cmd.command("powershell Get-Service -Name cdpusersvc, SSDPSRV, CDPSvc, EventLog, SysMain, PcaSvc, VSS, diagtrack, dps, vmicvss");
	
	//misc.cleanprefetch();
	//misc.modificationDate("D:\\Repos\\html\\sex");

	return 0;	
}