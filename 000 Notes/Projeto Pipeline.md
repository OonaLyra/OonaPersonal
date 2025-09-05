# Created data

### Colunas criadas

Tempo de Relacionamento
Ticket médio
Status(Inativo/Ativo)


---

### Métricas Criadas

Cálculo do tempo de relacionamento:
=((ANO($E2)-ANO($D2))*12+(MÊS($E2)-MÊS($D2)))

Ticket médio
=SE($G2>0; $F2/$G2; "0")

Medidor de inatividade:
=SE(DIAS(HOJE(); E2) < 45; "Ativo"; "Inativo")

Taxa de retenção:
=(CONT.SE($N$2:$N$301; "Ativo"))/(CONT.VALORES($N$2:$N$301))

Cálculo de receita por especialidades
=SOMASE(Dados!$B$2:$B$301; $A2; Dados!$F$2:$F$301)/CONT.SE(Dados!$B$2:$B$301; $A2)

Prescritores por região
=CONT.SE(Dados!$C$2:$C$301; $A15)

Ticket médio por prescritor de cada região
=SOMASE(Dados!$C$2:$C$301; $A15; Dados!$M$2:$M$301)/$B15

Prescritores por faixa de ticket:
=CONT.SE(Dados!$C$2:$C$301; "<=299")

# Caminho a se seguir
### E
Baixar dataset bruto
Documentar no Obsidian: fonte, periodicidade, dicionário inicial.
Criar uma pasta /data/raw no GitHub para armazenar versão original.

### T
Usar Pandas para:
Limpeza (nulos, duplicados, tipos errados).
Padronização de colunas(snake_case)
Criação de novas coluna
Salvar dataset transformado em /data/processed.
Documentar as transformações

### L
Carregar CSV limpo no Power BI via Power Query.
Criar modelagem dimensional (fato + dimensões).

---

# Estrutura no github
estrutura de pastas no GitHub

etl-sales-pipeline/
|
|── data/
|   ── raw/          
|   ── processed/    
|
|── notebooks/       
|   ── etl.ipynb
|   ── eda.ipynb
|
|── dashboard/        
|
|── docs/             
|
|── README.md     


---

# Gráficos feitos até agora
# Gráfico da distribuição das prescrições
```python
# Gráfico da distribuição de prescrições
plt.figure(figsize=(4, 2))
sns.histplot(df['Total de Prescrições'], kde=True)
plt.title('Distribuição das Prescrições')
plt.show()

# Gráfico da quantidade de médicos por especialidade
sns.countplot(data=df, x='Especialidade')
plt.xticks(rotation=45)
plt.title('Quantidade de médicos por especialidade')
plt.show()
```
