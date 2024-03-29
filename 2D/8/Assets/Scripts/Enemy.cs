using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public float speed;
    public float health;

    public Sprite[] sprites;
    SpriteRenderer spriteRender;

    Rigidbody2D rd;

    public GameObject bulletPrefab;
    public float curBulletDelay = 0f;
    public float maxBulletDelay = 1f;

    public GameObject playerObject;

    public static int EnemyDead = 0;

    public GameObject[] EnemyItem = new GameObject[10]; //적기가 부서졌을때 생성되는 아이템

    void Awake()
    {
        rd = GetComponent<Rigidbody2D>();
        spriteRender = GetComponent<SpriteRenderer>();
    }
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        Fire();
        ReloadBullet();
    }

    void Fire()
    {
        if (curBulletDelay > maxBulletDelay)
        {
            Power();

            curBulletDelay = 0;
        }
    }

    void Power()
    {
        GameObject bulletObj = Instantiate(bulletPrefab, transform.position, Quaternion.identity);
        Rigidbody2D rdBullet = bulletObj.GetComponent<Rigidbody2D>();
        
        Vector3 dirVec = playerObject.transform.position - transform.position;
        rdBullet.AddForce(dirVec.normalized * 3, ForceMode2D.Impulse);
    }

    void ReloadBullet()
    {
        curBulletDelay += Time.deltaTime;
    }

    public void Move(int nPoint)
    {
        if (nPoint == 3 || nPoint == 4) // 오른쪽에 있는 스폰 포인트의 배열 인덳스값
        {
            transform.Rotate(Vector3.back * 90);
            rd.velocity = new Vector2(speed * (-1), -1);
        }
        else if (nPoint == 5 || nPoint == 6) // 왼쪽에 있는 스폰 포인트의 배열 인덳스값
        {
            transform.Rotate(Vector3.forward * 90);
            rd.velocity = new Vector2(speed, -1);
        }
        else
        {
            rd.velocity = Vector2.down * speed;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Border")
        {
            Destroy(gameObject);
        }
        else if (collision.gameObject.tag == "PlayerBullet")
        {
            Bullet bullet = collision.gameObject.GetComponent<Bullet>();
            OnHit(bullet.power);
            Destroy(collision.gameObject);
        }
    }

    private void OnHit(float BulletPower)
    {
        health -= BulletPower;
        spriteRender.sprite = sprites[1];
        Invoke("ReturnSprite", 0.1f);

        if (health <= 0)
        {
            int RandItem = Random.Range(0, 10); //랜덤아이템 3개 중 하나를 랜덤으로 선택
                                                //100% 중 확률을 나누기 위해 0부터 9까지의 수를 랜덤으로 하나 고름

            if (RandItem < 3) //30%확률로 아이템없음
            {
                //Debug.Log("Not Item");
            }
            else if (RandItem < 4) //10%확률로 PowerItem드랍
            {
                Instantiate(EnemyItem[0], transform.position, Quaternion.identity);
            }
            else if (RandItem < 6) //20%확률로 BombItem드랍
            {
                Instantiate(EnemyItem[1], transform.position, Quaternion.identity);
            }
            else if (RandItem < 10) //40%확률로 CoinItem드랍
            {
                Instantiate(EnemyItem[2], transform.position, Quaternion.identity);
            }

            Destroy(gameObject);
            EnemyDead ++;
        }
    }

    void ReturnSprite()
    {
        spriteRender.sprite = sprites[0];
    }
}
