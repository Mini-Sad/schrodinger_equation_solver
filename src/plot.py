import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Lire le titre et la valeur de n
with open('resultat.csv', 'r') as f:
    titre = f.readline().strip()
    n_line = f.readline().strip()

# Extraire n depuis la deuxième ligne
n = int(n_line) if n_line.isdigit() else 0

# Lire les données (skip 2 premières lignes)
df = pd.read_csv('resultat.csv', skiprows=2, header=None, names=['psi'])
df['psi'] = pd.to_numeric(df['psi'], errors='coerce')
df = df.dropna()

# Créer l'axe z
n_points = len(df)
z = np.linspace(-5, 5, n_points)
df['z'] = z

# Tracer
plt.figure(figsize=(12, 7))
plt.plot(df['z'], df['psi'], 'b-', linewidth=2, label=f'ψ_{n}(z)')
plt.axhline(y=0, color='k', linestyle='--', alpha=0.3)
plt.axvline(x=0, color='k', linestyle='--', alpha=0.3)
plt.xlabel('Position z', fontsize=14)
plt.ylabel(f'ψ_{n}(z)', fontsize=14)
plt.title(titre, fontsize=12)
plt.grid(True, alpha=0.3)
plt.legend(fontsize=12)
plt.tight_layout()
plt.savefig(f'oscillateur_n{n}.png', dpi=300)
plt.show()