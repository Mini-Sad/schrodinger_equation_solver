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

# 2. Graphique avec subplots séparés
# Calcul de la disposition optimale des subplots
n_cols = 3  # 3 colonnes
n_rows = (n_max + 1 + n_cols - 1) // n_cols  # Nombre de lignes nécessaires

fig, axes = plt.subplots(n_rows, n_cols, figsize=(15, 4*n_rows))
fig.suptitle(f'Oscillateur Harmonique 1D - États n=0 à n={n_max}', 
             fontsize=18, fontweight='bold', y=0.995)

# Aplatir le tableau d'axes pour faciliter l'itération
axes_flat = axes.flatten() if n_rows > 1 else [axes] if n_cols == 1 else axes

colors = plt.cm.viridis(np.linspace(0, 1, n_max+1))

for i in range(n_max + 1):
    ax = axes_flat[i]
    try:
        df = pd.read_csv(f'resultat_n{i}.csv', skiprows=1, header=None, names=['psi'])
        df['psi'] = pd.to_numeric(df['psi'], errors='coerce')
        df = df.dropna()
        
        n_points = len(df)
        z = np.linspace(-10, 10, n_points)
        
        # Tracer la fonction d'onde
        ax.plot(z, df['psi'], linewidth=2, color=colors[i])
        ax.axhline(y=0, color='k', linestyle='--', alpha=0.3, linewidth=0.8)
        ax.axvline(x=0, color='k', linestyle='--', alpha=0.3, linewidth=0.8)
        ax.set_xlabel('z', fontsize=11)
        ax.set_ylabel(f'ψ_{i}(z)', fontsize=11)
        ax.set_title(f'n={i}, E={0.5+i:.1f}ℏω', fontsize=12, fontweight='bold')
        ax.grid(True, alpha=0.2)
        
    except FileNotFoundError:
        ax.text(0.5, 0.5, f'n={i}\nNon disponible', 
                ha='center', va='center', transform=ax.transAxes, fontsize=12)
        ax.set_xticks([])
        ax.set_yticks([])

# Masquer les subplots vides restants
for i in range(n_max + 1, len(axes_flat)):
    axes_flat[i].axis('off')

plt.tight_layout()
plt.savefig(f'oscillateur_tous_etats.png', dpi=300, bbox_inches='tight')
print(f"\n✓ Graphique avec subplots séparés: oscillateur_tous_etats.png")

plt.show()

print(f"\n🎉 {n_max+1} graphiques individuels + 1 graphique combiné générés!")