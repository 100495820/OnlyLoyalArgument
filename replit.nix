{ pkgs }: {
	deps = [
   pkgs.xorg.xinit
   pkgs.i3
   pkgs.i3-gaps
   pkgs.neofetch
   pkgs.run
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}