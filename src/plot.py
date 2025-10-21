import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Lire le titre et la valeur de n
with open('resultat.csv', 'r') as f:
    titre = f.readline().strip()
    n_line = f.readline().strip()

# Extraire n depuis la deuxième ligne
n_max = int(n_line) if n_line.isdigit() else 0

print(f"Génération des graphiques pour n=0 à n={n_max}")

# 1. Graphiques individuels
for i in range(n_max + 1):
    try:
        df = pd.read_csv(f'resultat_n{i}.csv', skiprows=1, header=None, names=['psi'])
        df['psi'] = pd.to_numeric(df['psi'], errors='coerce')
        df = df.dropna()
        
        n_points = len(df)
        z = np.linspace(-10, 10, n_points)
        
        plt.figure(figsize=(10, 6))
        plt.plot(z, df['psi'], 'b-', linewidth=2)
        plt.axhline(y=0, color='k', linestyle='--', alpha=0.3)
        plt.axvline(x=0, color='k', linestyle='--', alpha=0.3)
        plt.xlabel('Position z', fontsize=14)
        plt.ylabel(f'ψ_{i}(z)', fontsize=14)
        plt.title(f'Oscillateur Harmonique 1D - État n={i}', fontsize=16)
        plt.grid(True, alpha=0.3)
        plt.tight_layout()
        plt.savefig(f'oscillateur_n{i}.png', dpi=300, bbox_inches='tight')
        plt.close()
        print(f"  ✓ oscillateur_n{i}.png")
    except FileNotFoundError:
        print(f"  ✗ Fichier resultat_n{i}.csv non trouvé")

# 2. Graphique combiné
plt.figure(figsize=(14, 10))
colors = plt.cm.viridis(np.linspace(0, 1, n_max+1))

for i in range(n_max + 1):
    try:
        df = pd.read_csv(f'resultat_n{i}.csv', skiprows=1, header=None, names=['psi'])
        df['psi'] = pd.to_numeric(df['psi'], errors='coerce')
        df = df.dropna()
        
        n_points = len(df)
        z = np.linspace(-10, 10, n_points)
        
        # Décalage vertical pour éviter le chevauchement
        offset = i * 0.3
        
        plt.plot(z, df['psi'] + offset, linewidth=2.5, 
                label=f'n={i} (E={0.5+i:.1f}ℏω)', color=colors[i])
    except FileNotFoundError:
        continue

plt.axhline(y=0, color='k', linestyle='--', alpha=0.3)
plt.axvline(x=0, color='k', linestyle='--', alpha=0.3)
plt.xlabel('Position z', fontsize=16)
plt.ylabel('ψ_n(z) + décalage', fontsize=16)
plt.title(f'Oscillateur Harmonique 1D - Tous les états (n=0 à {n_max})', fontsize=18, fontweight='bold')
plt.grid(True, alpha=0.3)
plt.legend(fontsize=12, loc='upper right', framealpha=0.9)
plt.tight_layout()
plt.savefig(f'oscillateur_tous_etats.png', dpi=300, bbox_inches='tight')
print(f"\n✓ Graphique combiné: oscillateur_tous_etats.png")

plt.show()

print(f"\n🎉 {n_max+1} graphiques individuels + 1 graphique combiné générés!")