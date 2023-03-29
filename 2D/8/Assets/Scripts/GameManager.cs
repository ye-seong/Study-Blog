using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Transform[] spawnPoints;
    public GameObject[] enemyPrefabs;

    public float curEnemySpawnDelay;
    public float nextEnemySpawnDelay;

    public GameObject player;

    public static GameManager gameManager;

    public GameObject[] enemybullet;

    public float godtime = 3;

    // Update is called once per frame
    void Update()
    {
        curEnemySpawnDelay += Time.deltaTime;
        if (curEnemySpawnDelay > nextEnemySpawnDelay)
        {
            SpawnEnemy();

            nextEnemySpawnDelay = Random.Range(0.5f, 3.0f);
            curEnemySpawnDelay = 0;
        }
    }

    private void Awake() //ΩÃ±€≈Ê ∆–≈œ
    {
        if (gameManager == null)
        {
            gameManager = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    void SpawnEnemy()
    {
        int ranType = Random.Range(0, 3);
        int ranPoint = Random.Range(0, 7);
        GameObject goEnemy = Instantiate(enemyPrefabs[ranType], spawnPoints[ranPoint].position, Quaternion.identity);
        Enemy enemyLogic = goEnemy.GetComponent<Enemy>();
        enemyLogic.playerObject = player;
        enemyLogic.Move(ranPoint);
    }

    public void GameOver()
    {
        enemybullet = GameObject.FindGameObjectsWithTag("EnemyBullet");
        for (int i = 0; i < enemybullet.Length; i++)
        {
            Destroy(enemybullet[i]);
        }

        player.SetActive(false);
        Time.timeScale = 0;


    }

    public void RespawnPlayer()
    {
        Invoke("AlivePlayer", 0.3f);

        player.GetComponent<PolygonCollider2D>().enabled = false;

        StartCoroutine(Flicker());

        Invoke("GodTime", 3.0f);
    }
        
    IEnumerator Flicker()
    {
        int count = 0;
        while (count < 3)
        {
            player.GetComponent<SpriteRenderer>().color = new Color(1, 1, 1, 0);
            yield return new WaitForSeconds(0.4f);
            player.GetComponent<SpriteRenderer>().color = new Color(1, 1, 1, 1);
            yield return new WaitForSeconds(0.4f);
            count++;
        }
    }

    void GodTime()
    {
        player.GetComponent<PolygonCollider2D>().enabled = true;
    }

    void AlivePlayer()
    {
        player.transform.position = Vector3.down * 4.2f;
        player.SetActive(true);
        Player playrLogic = player.GetComponent<Player>();
        playrLogic.isHit = false;
    }
}
