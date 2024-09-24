{
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      nativeBuildInputs = with pkgs; [ qmk ];
    in {
      devShells.${system}.default =
        pkgs.mkShell { inherit nativeBuildInputs system; };
    };
}

